# FLISDK Libs

Thư mục chứa toàn bộ binary frameworks và cấu hình phân phối cho **FLISDK** — SDK tích hợp camera an ninh FPT Camera trên iOS.

---

## Nội dung thư mục

```
Libs/
├── FLISDK.xcframework        # Core SDK (pre-built C++ binary)
├── WebRTC.xcframework        # Google WebRTC framework
├── FFmpeg/                   # FFmpeg xcframeworks
│   ├── TPFFmpeg.xcframework
│   ├── libavcodec.xcframework
│   ├── libavdevice.xcframework
│   ├── libavfilter.xcframework
│   ├── libavformat.xcframework
│   ├── libavutil.xcframework
│   ├── libpostproc.xcframework
│   ├── libswresample.xcframework
│   └── libswscale.xcframework
├── Package.swift             # Swift Package Manager manifest
├── Package.resolved          # Locked SPM dependencies
└── FLISDK.podspec            # CocoaPods spec
```

---

## Frameworks

### FLISDK.xcframework

Pre-built C++ binary chứa core protocol của SDK: device protocol, encoding, decoding và secure communication.

| Thuộc tính | Giá trị |
|---|---|
| Kiến trúc | `ios-arm64`, `ios-arm64-simulator` |
| Loại | XCFramework (binary) |
| Mục đích | Core device protocol, stream encoding |

### WebRTC.xcframework

Google WebRTC framework dùng cho streaming video real-time từ camera đến ứng dụng iOS.

| Thuộc tính | Giá trị |
|---|---|
| Kiến trúc | `ios-arm64`, `ios-arm64_x86_64-simulator` |
| Loại | XCFramework (binary) |
| Mục đích | Peer connection, ICE, video/audio codec |

### FFmpeg/ (tùy chọn)

Bộ FFmpeg xcframeworks để xử lý và chuyển đổi video codec. Mặc định bị comment trong podspec — chỉ bật khi cần tính năng transcode.

| Framework | Mục đích |
|---|---|
| `TPFFmpeg` | Wrapper tùy chỉnh cho FFmpeg |
| `libavcodec` | Codec encode/decode video/audio |
| `libavformat` | Container format (MP4, HLS...) |
| `libavfilter` | Bộ lọc video/audio |
| `libavutil` | Tiện ích dùng chung |
| `libavdevice` | Thiết bị input/output |
| `libswresample` | Resample audio |
| `libswscale` | Scale/chuyển đổi màu sắc |
| `libpostproc` | Post-processing video |

---

## Phân phối

### Swift Package Manager (SPM)

Thư mục này là một SPM package độc lập tên **FLISDKCore**.

**Yêu cầu:** iOS 13.0+, Swift 5.5+

**Thêm vào project qua Xcode:**

1. File > Add Package Dependencies
2. Nhập URL của repository này
3. Chọn package `FLISDKCore`

**Hoặc thêm vào `Package.swift` của project:**

```swift
dependencies: [
    .package(url: "<URL_CUA_REPO_NAY>", from: "1.0.0")
],
targets: [
    .target(
        name: "YourTarget",
        dependencies: ["FLISDKCore"]
    )
]
```

**Dependencies SPM (tự động giải quyết):**

| Package | Version | Mục đích |
|---|---|---|
| CocoaMQTT | 2.2.4 | MQTT client (signal updates, device status) |
| MqttCocoaAsyncSocket | 1.0.8 | Async socket cho MQTT |
| Starscream | 4.0.8 | WebSocket (MQTT over WS) |

---

### CocoaPods

**Podspec:** `FLISDK.podspec`

**Thêm vào `Podfile`:**

```ruby
pod 'FLISDK', :path => '<ĐƯỜNG_DẪN_ĐẾN_THƯ_MỤC_LIBS>'
```

**Cần thêm dependency CocoaMQTT vào Podfile:**

```ruby
pod 'CocoaMQTT', '~> 2.1'
```

**Chạy:**

```bash
pod install
```

**Bật FFmpeg** (nếu cần transcode): Uncomment dòng sau trong `FLISDK.podspec`:

```ruby
# 'FFmpeg/TPFFmpeg.xcframework'
```

---

## Yêu cầu hệ thống

| Yêu cầu | Giá trị |
|---|---|
| Platform | iOS 13.0+ |
| Swift | 5.5+ |
| Xcode | 13.0+ |
| Kiến trúc | arm64 (device), arm64 + x86_64 (simulator) |

---

## Thiết lập thủ công (không dùng package manager)

Nếu tích hợp trực tiếp vào Xcode project:

1. Kéo `FLISDK.xcframework` và `WebRTC.xcframework` vào project
2. Trong **Build Settings** > **Other Linker Flags**, thêm `-lc++`
3. Thêm CocoaMQTT thủ công hoặc qua SPM/CocoaPods
4. (Tùy chọn) Thêm các framework trong `FFmpeg/` nếu cần

---

## Liên hệ

- **Author:** TrucPN3 — trucpn3@fpt.com
- **Homepage:** http://fpt.com
- **License:** MIT
