include_directories(${GLIB2_INCLUDE_DIRS})
include_directories(${LIBXML2_INCLUDE_DIRS})
include_directories(${APPINDICATOR_INCLUDE_DIRS})
include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(${GSTREAMER_INCLUDE_DIRS})
include_directories(${GSTREAMERMM_INCLUDE_DIRS})
include_directories(${CURL_INCLUDE_DIRS})
include_directories(${LIBNOTIFY_INCLUDE_DIRS})
include_directories(${LIBMAGIC_INCLUDE_DIRS})

include_directories(SYSTEM third_party)

add_definitions(-Wno-deprecated-declarations)

set(
    PLAYLIST_DECODERS
    m3u_playlist_decoder.cpp
    pls_playlist_decoder.cpp
    asx_playlist_decoder.cpp
    ram_playlist_decoder.cpp
    xspf_playlist_decoder.cpp
)

set(
    THIRD_PARTY
    third_party/pugixml/pugixml.cpp
)

add_executable(
    radiostation
    radiostation.cpp
    tray.cpp
    player.cpp
    about.cpp
    playlist.cpp
    notification.cpp
    config.cpp
    options.cpp
    ${PLAYLIST_DECODERS}
    ${THIRD_PARTY}
)
target_link_libraries(
    radiostation
    ${LIBXML2_LIBRARIES}
    ${GSTREAMERMM_LIBRARIES}
    ${GTKMM_LIBRARIES}
    ${CURL_LIBRARIES}
    ${APPINDICATOR_LIBRARIES}
    ${LIBNOTIFY_LIBRARIES}
    ${LIBMAGIC_LIBRARIES}
)
set_target_properties(radiostation PROPERTIES COMPILE_FLAGS "-std=c++11")
target_compile_definitions(radiostation PRIVATE -DELPP_DISABLE_DEFAULT_CRASH_HANDLING)
target_compile_definitions(radiostation PRIVATE -DINSTALL_PREFIX="${CMAKE_INSTALL_PREFIX}")
target_compile_definitions(radiostation PRIVATE -DAPP_VERSION="${APP_VERSION}")

install(
    TARGETS radiostation
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_executable(
        radiostation-cli
        radiostation-cli.cpp
        player.cpp
        playlist.cpp
        config.cpp
        options.cpp
        ${PLAYLIST_DECODERS}
        ${THIRD_PARTY}
        )
    target_link_libraries(
        radiostation-cli
        ${LIBXML2_LIBRARIES}
        ${GSTREAMERMM_LIBRARIES}
        ${CURL_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        ${LIBMAGIC_LIBRARIES}
        )
    set_target_properties(radiostation-cli PROPERTIES COMPILE_FLAGS "-std=c++11")
    target_compile_definitions(radiostation-cli PRIVATE -DELPP_DISABLE_DEFAULT_CRASH_HANDLING)
    target_compile_definitions(radiostation-cli PRIVATE -DINSTALL_PREFIX="${CMAKE_INSTALL_PREFIX}")
    target_compile_definitions(radiostation-cli PRIVATE -DAPP_VERSION="${APP_VERSION}")

    install(
        TARGETS radiostation-cli
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        )
endif()
