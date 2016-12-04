Pod::Spec.new do |s|
    s.name         = 'PYSearch'
    s.version      = '0.4.0'
    s.summary      = 'An elegant search controller for iOS.'
    s.homepage     = 'https://github.com/iphone5solo/PYSearch'
    s.license      = 'MIT'
    s.authors      = {'CoderKo1o' => '499491531@qq.com'}
    s.platform     = :ios, '7.0'
    s.source       = {:git => 'https://github.com/iphone5solo/PYSearch.git', :tag => s.version}
    s.source_files = 'PYSearch/**/*.{h,m}'
    s.resource     = 'PYSearch/PYSearch.bundle'
    s.requires_arc = true
end


