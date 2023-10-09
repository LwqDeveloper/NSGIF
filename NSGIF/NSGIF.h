//
//  NSGIF.h
//
//  Created by Sebastian Dobrincu
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <ImageIO/ImageIO.h>
#import <AVFoundation/AVFoundation.h>

#if TARGET_OS_IPHONE
    #import <MobileCoreServices/MobileCoreServices.h>
    #import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
    #import <CoreServices/CoreServices.h>
    #import <WebKit/WebKit.h>
#endif

typedef NS_ENUM(NSInteger, NSGIFSize) {
    NSGIFSizeVeryLow  = 2,
    NSGIFSizeLow      = 3,
    NSGIFSizeMedium   = 5,
    NSGIFSizeHigh     = 7,
    NSGIFSizeOriginal = 10
};

@interface NSGIF : NSObject

+ (void)optimalGIFfromURL:(NSURL*)videoURL loopCount:(int)loopCount completion:(void(^)(NSURL *GifURL))completionBlock;

+ (void)createGIFfromURL:(NSURL*)videoURL framesPerSecond:(int)framesPerSecond delayTime:(float)delayTime loopCount:(int)loopCount GIFSize:(NSGIFSize)GIFSize completion:(void(^)(NSURL *GifURL))completionBlock;

+ (NSGIFSize)recommendGIFSizefromURL:(NSURL*)videoURL;

@end
