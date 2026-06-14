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
                arguments += "-DBUILD_TESTING=OFF"
                arguments += "-DCMAKE_SKIP_TESTS=ON"
                arguments(
                    "-DCMAKE_CROSSCOMPILING_EMULATOR="
                )
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