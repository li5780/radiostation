#ifndef __XSPF_PLAYLIST_DECODER_HPP_INCLUDED__
#define __XSPF_PLAYLIST_DECODER_HPP_INCLUDED__

#include <iomanip>
#include <sstream>

#include "playlist_decoder.hpp"
#include "pugixml/pugixml.hpp"

namespace radiostation
{
class XSPFPlaylistDecoder : public PlaylistDecoder
{
public:
    ~XSPFPlaylistDecoder() = default;

    bool is_valid(const std::string& content_type) const override;
    MediaStreams extract_media_streams(const std::string& data) override;
    std::string desc() const override;

private:
    pugi::xml_document playlist_doc;
};

} // namespace radiostation

#endif
