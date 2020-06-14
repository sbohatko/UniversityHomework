Installation
Deno ships as a single executable with no dependencies. 
You can install it using the installers below, or download a release binary from the releases page.

Shell (Mac, Linux):
$
curl -fsSL https://deno.land/x/install/install.sh | sh
PowerShell (Windows):
$
iwr https://deno.land/x/install/install.ps1 -useb | iex
Homebrew (Mac):
$
brew install deno
Chocolatey (Windows):
$
choco install deno
Scoop (Windows):
$
scoop install deno
Build and install from source using Cargo
$
cargo install deno


How to start server

Use "deno run --allow-net --allow-read main.ts" to run the application

Than type "localhost:8000" in browser, to see if it work

After you visit the website, you will see timing of your visit in console.