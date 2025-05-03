# Qt-DBus-Session-Bus-Example

Bu proje, Qt framework kullanılarak iki ayrı Qt uygulaması (Client ve Server) arasında **D-Bus (Session Bus)** üzerinden mesajlaşma örneği sunar. QML arayüzü ve C++ altyapısıyla, D-Bus sinyal ve metodlarının nasıl kullanılabileceğini gösteren öğretici bir çalışmadır.

## 📦 Proje Yapısı

Proje iki ayrı uygulamadan oluşur:

- `Qt-DBus-Server.`: D-Bus üzerinden mesaj alan servis (method alır).
- `Qt-DBus-Client.`: Server’a D-Bus üzerinden mesaj gönderen istemci.

Her iki uygulama da Qt 5.15 veya Qt 6 ile uyumludur.

## 🚀 Özellikler

- QML tabanlı sade arayüz
- Session Bus üzerinden IPC (Inter-Process Communication)
- D-Bus metodu çağırma (Client -> Server)
- D-Bus üzerinden veri gönderimi
- Ayrı Qt projeleri arasında iletişim

## 🔧 Kurulum

### 1. Bu repoyu klonla:

```bash
git clone https://github.com/kenanozt1/Qt-DBus-Communication-Example.git
cd Qt-DBus-Communication-Example
```

### 2. Qt ile projeleri derle

Her bir dizindeki `*.pro` dosyasını Qt Creator ile açarak veya terminalden derleyebilirsin:

```bash
cd Qt-DBus-Server
qmake && make

cd ../Qt-DBus-Client
qmake && make
```

## ▶️ Kullanım

1. **Qt-DBus-Server** uygulamasını başlat. Bu uygulama D-Bus servisini başlatır ve gelen istemci mesajlarını dinler.
2. **Qt-DBus-Client** uygulamasını başlat. Bu uygulama Server’a D-Bus üzerinden mesaj gönderir.

Client uygulamasındaki butona bastığında, Server uygulaması bu mesajı terminale veya arayüzüne yazdırır.

## 📡 Faydalı D-Bus Komutları

Proje çalışırken terminalde aşağıdaki komutları deneyebilirsin:

```bash
# D-Bus mesajlarını dinle
dbus-monitor --session "type='method_call',interface='org.example.dbus'"

# Servis ve nesne kontrolü
qdbus org.example.dbus /message
```

## 💡 Geliştirme Notları

- Bu örnek sadece `Session Bus` kullanır. `System Bus` için `dbus policy` dosyası gerekir.
- Gerçek uygulamalarda mesajların doğrulanması ve hata yönetimi önerilir.

---

## 🛠 Gereksinimler

- Qt 5.15+ veya Qt 6
- Linux D-Bus (genellikle tüm masaüstü Linux’larda kurulu olur)

---

## 🧑‍💻 Geliştirici

**Kenan Öztürk**  
[Sivas Cumhuriyet Üniversitesi – Bilgisayar Mühendisliği]  
GitHub: [@kenanozt1](https://github.com/kenanozt1)

---

## 📄 Lisans

# Qt-DBus-Session-Bus-Example (English)
This project presents an example of communication between two separate Qt applications (Client and Server) over **D-Bus (Session Bus)** using Qt framework. It is an educational work demonstrating how D-Bus signals and methods can be used with QML interface and C++ backend.

## 📦 Project Structure
The project consists of two separate applications:
- `Qt-DBus-Server`: Service that receives messages over D-Bus (receives method calls).
- `Qt-DBus-Client`: Client that sends messages to the Server over D-Bus.
Both applications are compatible with Qt 5.15 or Qt 6.

## 🚀 Features
- Simple QML-based interface
- IPC (Inter-Process Communication) over Session Bus
- D-Bus method calling (Client -> Server)
- Data transmission over D-Bus
- Communication between separate Qt projects

## 🔧 Installation
### 1. Clone this repository:
```bash
git clone https://github.com/kenanozt1/Qt-DBus-Communication-Example.git
cd Qt-DBus-Communication-Example
```
### 2. Compile the projects with Qt
You can open each `*.pro` file with Qt Creator or compile from the terminal:
```bash
cd Qt-DBus-Server
qmake && make
cd ../Qt-DBus-Client
qmake && make
```

## ▶️ Usage
1. Start the **Qt-DBus-Server** application. This application starts the D-Bus service and listens for incoming client messages.
2. Start the **Qt-DBus-Client** application. This application sends messages to the Server over D-Bus.
When you press the button in the Client application, the Server application prints this message to the terminal or its interface.

## 📡 Useful D-Bus Commands
You can try the following commands in the terminal while the project is running:
```bash
# Listen to D-Bus messages
dbus-monitor --session "type='method_call',interface='org.example.dbus'"
# Service and object check
qdbus org.example.dbus /message
```

## 💡 Development Notes
- This example only uses `Session Bus`. A `dbus policy` file is required for `System Bus`.
- Message validation and error handling are recommended for real applications.

---
## 🛠 Requirements
- Qt 5.15+ or Qt 6
- Linux D-Bus (usually installed on all desktop Linux distributions)

---
## 🧑‍💻 Developer
**Kenan Öztürk**  
[Sivas Cumhuriyet University - Computer Engineering]  
GitHub: [@kenanozt1](https://github.com/kenanozt1)

---
## 📄 License
This project is licensed under the MIT License. See the `LICENSE` file for details.

Bu proje MIT Lisansı ile lisanslanmıştır. Detaylar için `LICENSE` dosyasına bakınız.
