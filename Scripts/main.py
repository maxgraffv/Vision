import torch
import torch.nn as nn
import torch.nn.functional as F
import torchvision
from torchvision import datasets, transforms
from torch.utils.data import DataLoader
import matplotlib.pyplot as plt

# 🔧 Ustawienia
batch_size = 64
epochs = 10
learning_rate = 0.001
device = torch.device('cuda' if torch.cuda.is_available() else 'mps' if torch.mps.is_available() else 
                      'cpu')

print("Using ", device)

# 🔄 Przekształcenia (resize MNIST to 16x16)
transform = transforms.Compose([
    transforms.Resize((16, 16)),
    transforms.ToTensor()
])

# 📥 Dane
train_data = datasets.MNIST(root='./data', train=True, download=True, transform=transform)
test_data  = datasets.MNIST(root='./data', train=False, download=True, transform=transform)

train_loader = DataLoader(train_data, batch_size=batch_size, shuffle=True)
test_loader  = DataLoader(test_data, batch_size=batch_size)

# 🧠 Model
class SimpleCNN(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(1, 8, kernel_size=3, padding=1)
        self.conv2 = nn.Conv2d(8, 16, kernel_size=3, padding=1)
        self.fc1 = nn.Linear(16 * 4 * 4, 64)
        self.fc2 = nn.Linear(64, 10)

    def forward(self, x):
        x = F.relu(self.conv1(x))       # (8, 16, 16)
        x = F.max_pool2d(x, 2)          # (8, 8, 8)
        x = F.relu(self.conv2(x))       # (16, 8, 8)
        x = F.max_pool2d(x, 2)          # (16, 4, 4)
        x = x.view(-1, 16 * 4 * 4)      # flatten
        x = F.relu(self.fc1(x))         # (64,)
        x = self.fc2(x)                 # (10,)
        return x

model = SimpleCNN().to(device)

# ⚙️ Loss i optymalizator
criterion = nn.CrossEntropyLoss()
optimizer = torch.optim.AdamW(model.parameters(), lr=learning_rate)

# 🚀 Trening
for epoch in range(epochs):
    model.train()
    total_loss = 0
    for images, labels in train_loader:
        images, labels = images.to(device), labels.to(device)

        optimizer.zero_grad()
        outputs = model(images)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()

        total_loss += loss.item()

    print(f"Epoch {epoch+1}/{epochs}, Loss: {total_loss/len(train_loader):.4f}")

# ✅ Test
model.eval()
correct = 0
total = 0
with torch.no_grad():
    for images, labels in test_loader:
        images, labels = images.to(device), labels.to(device)
        outputs = model(images)
        _, predicted = torch.max(outputs.data, 1)
        total += labels.size(0)
        correct += (predicted == labels).sum().item()

print(f"Test Accuracy: {100 * correct / total:.2f}%")

# 👁️‍🗨️ Przykładowe predykcje
images, labels = next(iter(test_loader))
images = images.to(device)
outputs = model(images)
_, predicted = torch.max(outputs, 1)

plt.figure(figsize=(10, 3))
for i in range(10):
    plt.subplot(2, 5, i+1)
    plt.imshow(images[i].cpu().squeeze(), cmap='gray')
    plt.title(f"Label: {labels[i]}\nPred: {predicted[i].item()}")
    plt.axis('off')
plt.tight_layout()
plt.show()

