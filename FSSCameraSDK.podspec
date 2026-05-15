Pod::Spec.new do |spec|
  spec.name         = 'FSSCameraSDK'
  spec.version      = '1.0.0'
  spec.summary      = 'FSSCameraSDK - Giải pháp xem camera an ninh FPT Camera trên iOS.'
  spec.description  = 'FSSCameraSDK cung cấp các framework đã được build sẵn, giúp ứng dụng iOS dễ dàng tích hợp chức năng xem và giám sát camera an ninh FPT Camera, đáp ứng yêu cầu về hiệu năng và bảo mật.'
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
    ss.libraries = 'c++'
    ss.vendored_frameworks = [
      'FSS/*.xcframework'
    ]
  end
   # Nếu framework cần dynamic linking, bật module map
    spec.libraries = 'c++'  # Hoặc thêm các thư viện cần thiết khác
    # spec.frameworks = 'AVFoundation', 'CoreMedia', 'VideoToolbox' # Các framework hệ thống cần
end