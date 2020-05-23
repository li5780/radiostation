#ifndef __ASX_PLAYLIST_DECODER_HPP_INCLUDED__
#define __ASX_PLAYLIST_DECODER_HPP_INCLUDED__

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>

#include "playlist_decoder.hpp"

namespace radiostation
{
class ASXPlaylistDecoder : public PlaylistDecoder
{
public:
    ASXPlaylistDecoder();
    ~ASXPlaylistDecoder() override;

    bool is_valid(const std::string& content_type) const override;
    MediaStreams extract_media_streams(const std::string& data) override;
    std::string desc() const override;

private:
};

} // namespace radiostation

#endif
