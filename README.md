# Crypto Tracker

## Overview
This is a simple personal project to learn how APIs work with C++. The program makes a request to the server and parses the response to pass to an ncruses renderer.

## Structure

The code follows a rigid structure:
- Main -> main.cpp
- Main logic loop -> app/
- Internal logic -> core/
- HTTP and API calls -> api/
- Rendering and UI -> ui/

Each directory has a CMakeLists.txt to keep it organized.

## Running

The application.cpp file is set up initially to use the mock_server_client class, which will ping for responses from [ Fake Crypto API Server ](https://github.com/BroDudeGuyMan/fake_crypto_data_api).
You can change this to the included coin_gecko_client class, or make your own for whatever API you choose.
