// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "FLISDKCore",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(name: "FLISDKCore", targets: [ "FLISDKCore" ])
    ],
    dependencies: [
        .package(url: "https://github.com/emqx/CocoaMQTT.git", from: "2.1.9"),
    ],
    targets: [
       .binaryTarget(
            name: "WebRTC",
            path: "WebRTC.xcframework"
        ),
         .binaryTarget(
            name: "FLISDK",
            path: "FLISDK.xcframework"
        ),
       .target(
            name: "FLISDKCore",
            dependencies: [
                "WebRTC",
                "FLISDK",
                "CocoaMQTT"
            ],
            path: "",
            swiftSettings: [
                .define("BUILD_LIBRARY_FOR_DISTRIBUTION", .when(configuration: .release)),
                .define("IS_SWIFT_PACKAGE")
            ],
            linkerSettings: [
                .linkedLibrary("c++")
            ]
        )
    ]
)