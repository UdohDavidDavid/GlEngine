#ifndef SETTINGS_H
#define SETTINGS_H

namespace Settings
{
    // WINDOW SETTINGS
    inline constexpr float WindowWidth       = 800.0f;
    inline constexpr float WindowHeight      = 600.0f;
    inline bool Fullscreen                   = false;
    inline bool Vsync                        = false;
    inline constexpr const char* WindowTitle = "Opengl Engine";

    // Graphic Settings
    inline float FOV                         = 60.0f;
    inline int MSAASamples                   = 4;
    inline bool AnistrophicFiltering         = true;
    inline float AmbienceIntensity           = 0.1f;
    inline float DiffuseIntensity            = 0.5f;
    inline bool wireFrame                    = false;
    inline float background[]                = {0.0f, 0.0f, 0.0f};

    // Camera Settings;
    inline constexpr float YAW               = -90.0f;
    inline constexpr float PITCH             =  0.0f;
    inline float SENSITIVITY                 = 0.1f;
    inline float CameraSpeed                 = 7.5f;

}

#endif
