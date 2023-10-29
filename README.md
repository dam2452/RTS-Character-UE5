# RTS Character for Unreal Engine 5

## Overview
`ARTS_Character` is a custom character class designed for a Real-Time Strategy (RTS) style game, enabling a flying camera perspective. This character class allows developers to seamlessly move, rotate, and zoom using the specified input configurations.

## Features

1. **RTS Camera Movement:** Smooth movement, rotation, and zoom functions are integrated to offer a fluid camera experience typical in RTS games.
2. **Input Actions:** Custom input actions to handle camera movement, rotation, and zoom.
3. **Camera Components:** Integrated SpringArm and Camera components to provide a holistic camera setup.
4. **Overhead UI:** An embedded overhead widget for additional UI elements.
5. **Network Replication:** Network functions are available to ensure synchronized gameplay across clients in a multiplayer setting.

## Usage

### Properties

#### Input Actions
- `InputMappingContext`: Context for input mappings.
- `MoveAction`: Action mapping for camera movement.
- `RotateAction`: Action mapping for camera rotation.
- `ZoomAction`: Action mapping for camera zoom.

#### Camera Components
- `CameraBoom`: Spring arm component responsible for the camera's distance from the focal point.
- `FollowCamera`: The actual camera component capturing the player's view.
- `OverheadWidget`: UI widget that can be customized for any overhead elements.

#### Movement Variables
- `DesiredLocation`: Target location to which the camera should move.
- `Movement_Interp`: Interpolation rate for movement.
- `Movement_Speed`: Speed at which the camera moves.

#### Rotation Variables
- `DesiredYawRotation`: Target yaw rotation value.
- `Rotation_Interp`: Interpolation rate for rotation.
- `Rotation_Speed`: Speed at which the camera rotates.

#### Zoom Variables
- `DesiredZoom`: Target zoom value.
- `ZoomSpeed`: Speed of the zoom action.
- `Zoom_Interp`: Interpolation rate for zoom.
- `MinZoomDistance`: Minimum distance to which the camera can zoom in.
- `MaxZoomDistance`: Maximum distance to which the camera can zoom out.

### Network Functions
- `Multicast_SetDesiredLocation`: A function that is called on all clients to set the desired location.
- `Server_HandleInput`: A server-side function to handle and validate the input.

### Methods

- `HandleInput`: Central method to manage Move, Rotate, and Zoom inputs.
- `UpdateMovement`, `UpdateRotation`, `UpdateZoom`: Functions to refresh character's position, rotation, and zoom respectively, per tick.
- `Move`, `Rotate`, `Zoom`: Individual methods to handle the corresponding input actions.

## Setup

1. **Integration**: To use the `ARTS_Character` in your project, ensure you include the header `"RTS_Character.h"` and set up the necessary input mappings in the project settings.
2. **Configuration**: Adjust the properties like Movement_Speed, Rotation_Speed, ZoomSpeed, etc., to fit the desired gameplay feel.
3. **Networking**: If you're working on a multiplayer game, ensure your game server is correctly set up to handle and validate inputs across clients using the provided server functions.

## Conclusion
`ARTS_Character` provides a comprehensive solution for those looking to implement an RTS-style flying camera in Unreal Engine 5. With customizable input actions and adjustable properties, it offers both flexibility and ease of use. Whether you're building a single-player RTS or a multiplayer game, `ARTS_Character` is an excellent starting point.
