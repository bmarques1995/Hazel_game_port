param (
    [string]$buildMode = "Debug"
)

if ($buildMode -eq "Debug" -or $buildMode -eq "Release") {
    Write-Output "Build mode is $buildMode"
} else {
    Write-Output "Build mode not set or invalid, the default is the debug mode"
    $buildMode = "Debug"
}

$installPrefix = Join-Path (Get-Location) "Windows\$buildMode"

./installers/spdlog $buildMode $installPrefix
./installers/glfw $buildMode $installPrefix
./installers/glad $buildMode $installPrefix
./installers/imgui $buildMode $installPrefix
./installers/stb $buildMode $installPrefix
./installers/glm $buildMode $installPrefix

