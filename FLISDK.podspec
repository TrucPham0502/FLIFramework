Pod::Spec.new do |spec|
  spec.name         = 'FLISDK'
  spec.version      = '1.0.0'
  spec.summary      = 'FLISDK - Giải pháp xem camera an ninh FPT Camera trên iOS.'
  spec.description  = 'FLISDK cung cấp các framework đã được build sẵn, giúp ứng dụng iOS dễ dàng tích hợp chức năng xem và giám sát camera an ninh FPT Camera, đáp ứng yêu cầu về hiệu năng và bảo mật.'
  spec.homepage     = 'http://fpt.com'
  spec.license      = { :type => 'MIT', :file => 'LICENSE' }
  spec.author       = { 'TrucPN3' => 'trucpn3@fpt.com' }
  spec.platform     = :ios, '13.0'

  spec.source = {
    :path => '.'
  }

  spec.default_subspec = 'Core'

  spec.subspec 'Core' do |ss|
    ss.dependency 'CocoaMQTT'

    ss.libraries = 'c++', 'expat', 'z', 'iconv', 'resolv', 'xml2'

    ss.frameworks = 'OpenAL',
                    'AVFoundation',
                    'AudioToolbox',
                    'CoreAudio',
                    'CoreVideo',
                    'CoreMedia',
                    'VideoToolbox',
                    'Network',
                    'SystemConfiguration',
                    'CoreTelephony'

    ss.vendored_frameworks = [
      'WebRTC.xcframework',
      'FLISDK.xcframework',
      # 'FFmpeg/TPFFmpeg.xcframework'
    ]
  end

  spec.pod_target_xcconfig = { 'BUILD_LIBRARY_FOR_DISTRIBUTION' => 'YES' }
end