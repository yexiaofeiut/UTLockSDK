Pod::Spec.new do |s|
  s.name = "UTLockSDK"
  s.version = "0.1.1"
  s.summary = "A short description of UTLockSDK."
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"yexiaofeiut"=>"yexiaofei@ut.cn"}
  s.homepage = "https://github.com/yexiaofeiut/UTLockSDK"
  s.description = "TODO: Add long description of the pod here."
  s.frameworks = "YTKNetwork"
  s.source = { :git => 'https://github.com/yexiaofeiut/UTLockSDK.git', :tag => s.version.to_s}
  s.ios.deployment_target    = '8.0'
  s.ios.vendored_framework   = 'UTLockSDK.framework'
end
