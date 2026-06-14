plugins {
    alias(libs.plugins.android.application)
}

android {
    namespace = "com.draw.pontinho"
    compileSdk {
        version = release(36) {
            minorApiLevel = 1
        }
    }

    defaultConfig {
        applicationId = "com.draw.pontinho"
        minSdk = 23
        targetSdk = 36
        versionCode = 1
        versionName = "1.0"
        externalNativeBuild {
            cmake {
                cppFlags += "-std=c++17"
            }
        }
    }

    externalNativeBuild {
        cmake {
            path = file("../../CMakeLists.txt")
            version = "4.1.2"
        }
    }
}