/*
  SDP parsing and management

  Copyright (c) 2014 Diedrick H, as part of his "SDP" Github repository at https://github.com/diederickh/SDP
  License -- none given. Internet archive page as of 10Jan21 https://web.archive.org/web/20200918222637/https://github.com/diederickh/SDP

  Copyright (c) 2021 Signalogic, Dallas, Texas

  Revision History
    Modified Jan 2021 JHB, add a=rtpmap attribute support
*/

#include <sdp/utils.h>

namespace sdp {

  bool string_to_net_type(std::string& input, NetType& result) {

    result = SDP_NETTYPE_NONE;

    if (input.size() == 0) {
      return false;
    }

    if (input == "IN") {
      result = SDP_IN;
      return true;
    }

    return false;
  }

  /* convert a string to an AddrType */
  bool string_to_addr_type(std::string& input, AddrType& result) {

    result = SDP_ADDRTYPE_NONE;

    if (input.size() == 0) {
      return false;
    }

    if (input == "IP4") {
      result = SDP_IP4;
    }
    else if (input == "IP6") {
      result = SDP_IP6;
    }

    return result != SDP_ADDRTYPE_NONE;
  }

  /* convert a string to a CodecType */
  bool string_to_codec_type(std::string& input, CodecType& result) {

    result = SDP_CODECTYPE_NONE;

    if (input.size() == 0) {
      return false;
    }

    if (input == "AMR" || input == "AMR-NB") {
      result = SDP_AMRNB;
    }
    else if (input == "AMR-WB") {
      result = SDP_AMRWB;
    }
    else if (input == "EVS") {
      result = SDP_EVS;
    }
    else if (input == "telephone-event") {
      result = SDP_TELEPHONE_EVENT;
    }

    return result != SDP_CODECTYPE_NONE;
  }

  /* convert a string to an MediaType */
  bool string_to_media_type(std::string& input, MediaType& result) {

    result = SDP_MEDIATYPE_NONE;

    if (input.size() == 0) {
      return false;
    }

    if (input == "video") {
      result = SDP_VIDEO;
    }
    else if (input == "audio") {
      result = SDP_AUDIO;
    }
    else if(input == "text") {
      result = SDP_TEXT;
    }
    else if(input == "message") {
      result = SDP_MESSAGE;
    }
    else if(input == "application") {
      result = SDP_APPLICATION;
    }

    return result != SDP_MEDIATYPE_NONE;
  }

  /* convert a string to an MediaProto */
  bool string_to_media_proto(std::string& input, MediaProto& result) {

    result = SDP_MEDIAPROTO_NONE;

    if (input.size() == 0) {
      return false;
    }

    if (input == "udp") {
      result = SDP_UDP;
    }
    else if (input == "RTP/AVP") {
      result = SDP_RTP_AVP;
    }
    else if(input == "RTP/SAVP") {
      result = SDP_RTP_SAVP;
    }
    else if(input == "RTP/SAVPF") {
      result = SDP_RTP_SAVPF;
    }

    return result != SDP_MEDIAPROTO_NONE;
  }

  /* convert a string to a candidate type */
  bool string_to_cand_type(std::string& input, CandType& result) {

    result = SDP_CANDTYPE_NONE;

    if (input.size() == 0) {
      return false;
    }

    if (input == "host") {
      result = SDP_HOST;
    }
    else if (input == "host") {
      result = SDP_HOST;
    }
    else if(input == "srflx") {
      result = SDP_SRFLX;
    }
    else if(input == "prflx") {
      result = SDP_PRFLX;
    }
    else if(input == "relay") {
      result = SDP_RELAY;
    }

    return result != SDP_CANDTYPE_NONE;
  }

  std::string net_type_to_string(NetType type) {
    switch (type) {
      case SDP_IN: { return "IN"; } 
      default: { return "unknown"; }
    };
  }

  std::string addr_type_to_string(AddrType type) {
    switch (type) {
      case SDP_IP4: { return "IP4"; } 
      case SDP_IP6: { return "IP6"; } 
      default: { return "unknown"; }
    };
  }

  std::string codec_type_to_string(CodecType type) {
    switch (type) {
      case SDP_AMRNB: { return "AMR-NB"; } 
      case SDP_AMRWB: { return "AMR-WB"; } 
      case SDP_EVS: { return "EVS"; } 
      case SDP_TELEPHONE_EVENT: { return "telephone-event"; } 
      default: { return "unknown"; }
    };
  }

  std::string media_type_to_string(MediaType type) {
    switch (type) {
      case SDP_VIDEO:        { return "video";          } 
      case SDP_AUDIO:        { return "audio";          } 
      case SDP_TEXT:         { return "text";           } 
      case SDP_APPLICATION:  { return "application";    } 
      case SDP_MESSAGE:      { return "message";        } 
      default:               { return "unknown";        } 
    }
  }

  std::string media_proto_to_string(MediaProto proto) {
    switch (proto) {
      case SDP_UDP:        { return "udp";       } 
      case SDP_RTP_AVP:    { return "RTP/AVP";   } 
      case SDP_RTP_SAVP:   { return "RTP/SAVP";  } 
      case SDP_RTP_SAVPF:  { return "RTP/SAVPF"; } 
      default:             { return "unknown";   } 
    };
  }

  std::string cand_type_to_string(CandType type) {
    switch (type) {
      case SDP_HOST:      { return "host";      } 
      case SDP_SRFLX:     { return "srflx";     } 
      case SDP_PRFLX:     { return "prflx";     } 
      case SDP_RELAY:     { return "relay";     }
      default:            { return "unknown";   } 
    }
  }

} /* namespace sdp */
