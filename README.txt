
Frame Class Reference

A collection of different representations of a single image captured from a camera.

A Frame object can include an arbitrary number of image representations in different formats or resolutions together with a time stamp and frame index.

If any of the configured Trackers require particular frame formats internally, these will be included in getNumImages()/getImage(). It is not possible to predict in advance exactly which frame formats will be used, however, so if you require a specific image representation you should request it using Vufora::setFrameFormat().

Frame implements the RAII pattern: A newly created frame holds new image data whereas copies share this data. The image data held by Frame exists as long as one or more Frame objects referencing this image data exist.

<https://library.vuforia.com/content/vuforia-library/en/reference/cpp/classVuforia_1_1Frame.html>
