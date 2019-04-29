# Table of Contents

[SigSRF Overview](#user-content-overview)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[Applications](#user-content-applications)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[Platforms Supported](#user-content-platformssupported)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[Telecom Mode](#user-content-telecommode)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[Telecom Mode Data Flow Diagram](#user-content-telecommodedataflowdiagram)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[Analytics Mode](#user-content-analyticsmode)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[Analytics Mode Data Flow Diagram](#user-content-analyticsmodedataflowdiagram)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[Multithreaded for High Performance](#user-content-multithreaded)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[Deployment Grade](#user-content-deploymentgrade)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[Software and I/O Architecture Diagram](#user-content-softwarearchitecturediagram)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[Packet and Media Processing Data Flow Diagram](#user-content-dataflowdiagram)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[When "Software Only" is Not Enough](#user-content-softwareonly)<br/>
[SDK and Demo Download](#user-content-sdkdemodownload)<br/>
[Install Notes](#user-content-installnotes)<br/>
[Demos](#user-content-demos)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[mediaMin and mediaTest (streaming media, transcoding, speech recognition, waveform file and USB audio processing, and more)](#user-content-mediamin_and_mediatest_demos)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[iaTest (image analytics)](#user-content-iatestdemo)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[paTest (predictive analytics from log data)](#user-content-patestdemo)<br/>
[Documentation, Support, and Contact](#user-content-documentationsupport)<br/>

<a name="Overview"></a>
# SigSRF Overview

The SigSRF (Streaming Resource Functions) SDK introduces a scalable approach to telecom, media, HPC, and AI servers.  The basic concept is to scale between cloud, private cloud, and Edge and IoT servers, while maintaining a cloud programming model.

The primary objectives of SigSRF software are:

* provide high performance software modules for telecom, media, AI (deep learning), and analytics streaming applications
* provide both telecom and analytics modes for (i) telecom and CDN applications and (ii) data analytics and web IT applications
* maintain a deployment grade solution.  All modules and sources have been through customer acceptance testing
* scale up without GPU if needed, and provide high capacity, "real-time at scale" streaming and processing
* scale down without ARM if needed, and provide IoT and Edge solutions for SWaP <sup>1</sup> constrained applications
* maintain full program compatibility with cloud servers, including open source software support, server architectures, latest programming languages, etc.

<a name="Applications"></a>
## Applications

SigSRF software is currently deployed in the following application areas:

* Session Border Controller (SBC)
* Media Gateway
* Lawful Intercept (LI)
* Network Analyzers
* Satcom and HF Radio Speech Compression
* R&D Labs and Workstations

<a name="PlatformsSupported"></a>
## Platforms Supported

SigSRF software is designed to run on (i) private, public, or hybrid cloud servers and (ii) embedded system servers.  Demos available on this page and the mediaTest/mediaMin demo pages are intended to run on any Linux server based on x86, ARM, and PowerPC, and on form-factors as small as mini- and micro-ITX.

SigSRF supports media delivery, transcoding, deep learning <sup>2</sup>, OpenCV, speech recognition <sup>2</sup>, and other calculation / data intensive applications.  For applications facing SWaP, latency, or bandwidth constraints, SigSRF software supports a wide range of coCPU&trade; and SoC embedded device targets while maintaining a cloud compatible software architecture (see [When Software Only is Not Enough](#user-content-beyondsoftwareonly) below).

SigSRF supports concurrent multiuser operation in a bare-metal environment, and in a KVM + QEMU virtualized environment, cores and network I/O interfaces appear as resources that can be allocated between VMs. VM and host users can share also, as the available pool of cores is handled by a physical layer back-end driver. This flexibility allows media, HPC, and AI applications to scale between cloud, enterprise, and remote vehicle/location servers.

<a name="TelecomMode"></a>
## Telecom Mode

Telecom mode is defined as direct handling of IP/UDP/RTP traffic.  This mode is sometimes also referred to as “clocked” mode, as a wall clock reference is required for correct jitter buffer operation.  Examples of telecom mode applications include network midpoints such as SBC (Session Border Controller) and media gateway, and endpoints such as handsets and softphones.  Typically telecom applications have hard requirements for real-time performance and latency.

<a name="TelecomModeDataFlowDiagram"></a>
### Telecom Mode Data Flow Diagram

![SigSRF software telecom mode data flow diagram](https://github.com/signalogic/SigSRF_SDK/blob/master/images/Streaming_packet_and_media_processing_data_flow_telecom_mode_RevA7.png?raw=true "SigSRF telecom mode data flow diagram")

<a name="AnalyticsMode"></a>
## Analytics Mode

Analytics mode is defined as indirect handling of IP/UDP/RTP traffic, where traffic is encapsulated or "one step removed", having been captured, copied, or relayed from direct traffic for additional processing.  This mode is sometimes also referred to as data driven or “clockless” mode, the latter description referring to jitter buffer packet processing either wholly or partially without a wall clock reference.  In general, analytics mode applications operate after real-time traffic has already occurred, although it may be incorrect to say "non-real-time" as they may need to reproduce or emulate the original real-time behavior.  Examples of analytics mode include Lawful Intercept (LI) and web IT data analytics such as speaker identification and automatic speech recognition (ASR). 

<a name="AnalyticsModeDataFlowDiagram"></a>
### Analytics Mode Data Flow Diagram

![SigSRF software analytics mode data flow diagram](https://github.com/signalogic/SigSRF_SDK/blob/master/images/Streaming_packet_and_media_processing_data_flow_analytics_mode_RevA7.png?raw=true "SigSRF analytics mode data flow diagram")

<a name="Multithreaded"></a>
## Multithreaded for High Performance

SigSRF library modules support multiple, concurrent packet and media processing threads, each typically running on one CPU core, to enable high performance on multicore platforms.  Session to thread allocation modes include linear and round-robin.  Threads may be optionally pinned to a CPU core.

<a name="DeploymentGrade"></a>
## Deployment Grade

SigSRF software is currently deployed in major carriers, LEAs, research organizations, and B2B enterprises.  Under NDA, and with end customer permission, it may be possible to provide more information on deployment locations.

SigSRF software, unlike many open source repositories, is not experimental or prototype, and has been through rigorous customer production testing.  Some of the signal processing modules have a history dating back to 2005, including deployments in telecom, communications, and aviation systems.  Packet processing modules include some components dating back to 2010, such as jitter buffer and XDAIS standardized codec interface, with a long history of telecom system deployment.

In addition to customer production testing, stress tests are always ongoing in Signalogic lab servers.  New releases must pass 672 hours (4 weeks) of continuous stress test at full capacity, running on HP DL380 series servers.  For more information on these tests, and Linux configuration used for high capacity operation, see [SigSRF Documentation](#user-content-documentationsupport) below.

<a name="SoftwareArchitectureDiagram"></a>
## SigSRF Software and I/O Architecture Diagram

Below is a SigSRF software and I/O architecture diagram.

![SigSRF software and streaming I/O architecture diagram](https://github.com/signalogic/SigSRF_SDK/blob/master/images/SigSRF_Software_Architecture_and_Packet_IO_RevA2.png?raw=true "SigSRF software and streaming I/O architecture diagram")

<a name="DataFlowDiagram"></a>
## SigSRF Packet and Media Processing Data Flow Diagram

Below is a SigSRF software streaming packet and media processing data flow diagram.  This is an expansion of the telecom mode and analytics mode data flow diagrams above, including shared library APIs used within a packet/media thread.

In addition to the APIs referenced below, SigSRF offers a simplified set of APIs that minimize user applications to session create/delete and packet push/pull.  mediaMin and mediaTest are the reference applications for the minimum API level and more detailed level, respectively.  Source code is published for both.

![SigSRF streaming packet and media processing data flow diagram](https://github.com/signalogic/SigSRF_SDK/blob/master/images/Streaming_packet_and_media_processing_data_flow_RevA4.png?raw=true "SigSRF streaming packet and media processing data flow diagram")

Some notes about the above data flow diagram:

   1) Data flow matches <a href="https://github.com/signalogic/SigSRF_SDK/blob/master/mediaTest_readme.md">mediaTest</a> application C source code (packet_flow_media_proc.c).  Subroutine symbols are labeled with pktlib, voplib, and alglib API names.

   2) A few areas of the flow diagram are somewhat approximated, to simplify and make easier to read.  For example, loops do not have "for" or "while" flow symbols, and some APIs, such as DSCodecEncode() and DSFormatPacket(), appear in the flow once, but actually may be called multiple times, depending on what signal processing algorithms are in effect.

   3) <b>Multisession</b>.  The "Input and Packet Buffering", "Packet Processing", and "Media Processing and Output" stages are per-session, and repeat for multiple sessions.  See <a href="https://github.com/signalogic/SigSRF_SDK/blob/master/mediaTest_readme.md#user-content-sessionconfig">Session Config</a> for more info.

   4) <b>Multichannel</b>.  For each session, The "Input and Packet Buffering", "Packet Processing", and "Media Processing and Output" stages of data flow are multichannel and optimized for high capacity channel processing.

   5) <b>Multithreaded</b>.  A copy of the above diagram runs per thread, with each thread typically consuming one CPU core in high performance applications.

   6) <b>Media signal processing and inference</b>.  The second orange vertical line divides the "packet domain" and "media domain".  DSStoreStreamData() and DSGetStreamData() decouple these domains in the case of unequal ptimes.  The media domain contains raw audio or video data, which allows signal processing operations, such as sample rate conversion, conferencing, filtering, echo cancellation, convolutional neural network (CNN) classification, etc. to be performed.  Also this is where image and voice analytics takes place, for instance by handing video and audio data off to another process.

<a name="BeyondSoftwareOnly"></a>
## When "Software Only" is Not Enough

Cloud solutions are sometimes referred to as "software only", but that's an Intel marketing term. In reality there is no software without hardware.  With the recent surge in deep learning / neural net chips attempting to emulate human intelligence -- and the ultra energy efficiency of the human brain -- hardware limitations have never been more apparent.  In addition to AI technology, a wide range of HPC applications face hardware contraints.  For 30 years people have failed to solve this with generic x86 processors, and it isn't likely to happen any time soon.

One promising solution is heterogeneous (mixed) cores that "front" streaming data and perform calculation intensive processing, combined with x86 cores that perform general processing.  The basic concepts are (i) move calculation intensive processing closer to the data, and (ii) use cores that are extremely energy efficient for data calculation purposes.  To enable mixed core processing, SigSRF supports coCPU&trade; technology, which adds NICs and up to 100s of coCPU cores to scale per-box streaming and performance density.  Examples of coCPU cores include GPU, neural net chips, and Texas Instruments multicore CPUs. coCPUs can turn conventional 1U, 2U, and mini-ITX servers into high capacity, energy efficient edge servers for media, HPC, and AI applications, solving SWaP, latency, and bandwidth contraints.  For example, an embedded AI server can operate independently of the cloud, acquiring new data and learning on the fly.

Available media processing and image analytics demos can make use of optional coCPU cards containing Texas Instruments c66x multicore CPUs (the demo programs will auto-discover coCPU hardware if installed -- coCPU hardware is not required for any of the demos).  Besides TI, the expectation is there will soon be additional, suitable multicore CPU cards due to the explosion in deep learning applications, which is driving new chip and card development.  For the time being, c66x series CPUs, although implemented in 45 nm, still provide a huge per-box energy efficiency advantage for applications with high amounts of convolution, FFT, and matrix operations.

<sup>1</sup> SWaP = size, weight, and power consumption<br/>
<sup>2</sup> In progress

<a name="SDKDemoDownload"></a>
# SDK and Demo Download

The SigSRF SDK and demo download consists of an install script and .rar files and includes:

   1) A limited eval / demo version of several SigSRF demos, including media transcoding, image analytics, and H.264 video streaming (ffmpeg acceleration).  For a detailed explanation of demo limits, see [Demos](#user-content-demos) below.

   2) C/C++ source code showing Pktlib and Voplib API usage (source and Makefiles for demo programs included)

   3) Concurrency examples, including stream, instance, and multiple user

All demos run on x86 Linux platforms.  The mediaTest and iaTest demos will also utilize one or more coCPU cards if found at run-time.  Example coCPU cards are <a href="http://processors.wiki.ti.com/index.php/HPC" target="_blank">shown here</a>, and can be obtained from TI, Advantech, or Signalogic.  Demo .rar files contain a coCPU software stack, including drivers.  As noted above, coCPU technology increases per-box energy efficiency and performance density.

<a name="InstallNotes"></a>
# Install Notes

Separate RAR packages are provided for different Linux distributions. Please choose the appropriate one or closest match. For some files, the install script will auto-check for kernel version and Linux distro version to decide which file version to install (including coCPU driver, if you have a coCPU card).

All .rar files and the auto install script must stay together in the same folder after downloading.

Note that the install script checks for the presence of the unrar command, and if not found it will install the unrar package.

Media transcoding demos require tcpreplay or other method to generate packet traffic (using as input pcap files included in the install).

## Sudo Privilege

The install script requires sudo root privilege.  In Ubuntu, allowing a user sudo root privilege can be done by adding the user to the “administrators” group (<a href="http://askubuntu.com/questions/168280/how#do#i#grant#sudo#privileges#to#an#existing#user" target="_blank">as shown here</a>).  In CentOS a user can be added to the “/etc/sudoers” file (<a href="https://wiki.centos.org/TipsAndTricks/BecomingRoot" target="_blank">as shown here</a>).  Please make sure this is the case before running the script.

## Building Test and Demo Applications

Test and demo application examples are provided as executables, C/C++ source code and Makefiles.  Executables may run, but if not (due to Linux distribution or kernel differences), they should be rebuilt using gcc.  To allow this, the install script checks for the presence of the following run-time and build related packages:  gcc, ncurses, lib-explain, and redhat-lsb-core (RedHat and CentOS) and lsb-core (Ubuntu).  These are installed if not found.

## Running the Install Script

To run the install script enter:

    > source autoInstall_Sig_BSDK_2017v2.sh

The script will then prompt as follows:

    1) Host
    2) VM
    Please select target for co-CPU software install [1-2]:

After choosing an install target of either Host or VM, the script will next prompt for an install option:

    1) Install SigSRF Software
    2) Install SigSRF Software with coCPU Option
    3) Uninstall SigSRF Software
    4) Check / Verify
    5) Exit
    Please select install operation to perform [1-4]:

If the install operation (1.) is selected, the script will prompt for an install path:

    Enter the path for SigSRF software installation:

If no path is entered the default path is /usr/local.

If needed, the Check / Verify option can be selected to generate a log for troubleshooting and tech support purposes.

<a name="Demos"></a>
# Demos

Available demos are listed below.  The iaTest and paTest demos do not have a functionality limit.  mediaTest demo functionality is limited as follows:

   1) Data limit.  Processing is limited to 3000 frames / payloads of data.  There is no limit on data sources, which include various file types (audio, encoded, pcap), network sockets, and USB audio.

   2) Concurrency limit.  Maximum number of concurrent instances is two and maximum number of channels per instance is 2 (total of 4 concurrent channels).

If you need an evaluation demo with an increased limit for a trial period, [contact us](#DocumentationSupport).

<a name="mediaMin_and_mediaTest_Demos"></a>
## mediaMin and mediaTest Demos

The <a href="https://github.com/signalogic/SigSRF_SDK/blob/master/mediaTest_readme.md">mediaMin and mediaTest demo page</a> gives example command lines for streaming media, transcoding, speech recognition, waveform file and USB audio processing, and more.  Some things you can do with mediaMin and mediaTest demo command lines:

  * transcoding between pcaps, for example EVS to AMR-WB, AMR-NB to G711, etc.
  * "AMR Player", play an AMR pcap (either AMR-WB or AMR-NB)
  * "EVS Player", play an EVS pcap
  * transcode multistream pcaps and merge all streams together into one output audio (for example, generate a "unified conversation" for voice pcaps)
  * Kaldi speech recognition on pcaps or audio files (ASR, 200k word vocabulary)
  * test codecs and compare output vs. 3GPP reference files
  * insert user-defined signal processing or inference into the real-time data flow
  * input and output .wav file and other audio format files
  * input and output USB audio
  * test and measure packet RFCs, jitter buffer, packet loss and other stats, and more
  
For both mediaMin and mediaTest, reference application C/C++ source code is included.  The demos are based on deployed production code used in high capacity, real-time applications.  If you need to make performance measurements, they will be accurate and competitive.

<a name="iaTestDemo"></a>
## iaTest Demo

The <a href="https://github.com/signalogic/SigSRF_SDK/blob/master/iaTest_readme.md">iaTest demo page</a> gives example command lines for image analytics and OpenCV testing.  The iaTest demo performs image analytics operations vs. example surveillance video files and allows per-core performance measurement and comparison for x86 and coCPU cores.  .yuv and .h264 file formats are supported.  Application C/C++ source code is included.

<a name="paTestDemo"></a>
## paTest Demo

The <a href="https://github.com/signalogic/SigSRF_SDK/blob/master/paTest_readme.md">paTest demo page</a> gives example command lines for a predictive analytics application that applies algorithms and deep learning to continuous log data in order to predict failure anomalies.  Application Java and C/C++ source code is included.

<a name="DocumentationSupport"></a>
# Documentation, Support, and Contact

## SigSRF Software Documentation

SigSRF documentation, including Quick Start command line examples, High Capacity Operation, API Usage, and other sections is located at:

 <a href="https://bit.ly/2UZXoaW" target="_blank">SigSRF Documentation</a>
 
## coCPU Users Guide

The <a href="https://bit.ly/2J18F3f" target="_blank">coCPU User Guide</a> provides information about coCPU hardware and software installation, test and demo applications, build instructions, etc.

## Technical Support / Questions

Limited tech support for the SigSRF SDK and coCPU option is available from Signalogic via e-mail and Skype.  You can ask for group skype engineer support using Skype Id "signalogic underscore inc" (replace with _ and no spaces).  For e-mail questions, send to "info at signalogic dot com".
