param (
    [string]$buildMode = "",
    [string]$installPrefix = ""
)

Write-Output "$installPrefix"

if (($buildMode -eq "Debug" -or $buildMode -eq "Release") -and ($installPrefix -ne ""))
{
    cmake -S ./modules/glad -B ./dependencies/glad -DCMAKE_BUILD_TYPE="$buildMode" -DCMAKE_INSTALL_PREFIX="$installPrefix"
    cmake --build ./dependencies/glad --config "$buildMode" --target install
} 
else 
{
    Write-Output "Invalid build args"
}