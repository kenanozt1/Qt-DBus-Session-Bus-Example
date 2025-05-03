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

Bu proje MIT Lisansı ile lisanslanmıştır. Detaylar için `LICENSE` dosyasına bakınız.
