param (
    [string]$buildMode = "",
    [string]$installPrefix = ""
)

Write-Output "$installPrefix"

if (($buildMode -eq "Debug" -or $buildMode -eq "Release") -and ($installPrefix -ne ""))
{
    cmake -S ./modules/stb -B ./dependencies/stb -DCMAKE_BUILD_TYPE="$buildMode" -DCMAKE_INSTALL_PREFIX="$installPrefix"
    cmake --build ./dependencies/stb --config "$buildMode" --target install
} 
else 
{
    Write-Output "Invalid build args"
}