/**
 * For copyright & license, see COPYRIGHT.txt.
 */

// #import "Log4Cocoa.h"
#import <Foundation/Foundation.h>
#import "L4LoggerProtocols.h"

// key component is that it is serializable
// there is something going on with NDC & MDC's that I don't understand

// message, timestamp, exception for locaion info.

//  implements java.io.Serializable

@class L4Level, L4Logger;

@interface L4LoggingEvent : NSObject {
    NSNumber *lineNumber;
    NSString *fileName;
    NSString *methodName;
    L4Logger *logger;
    L4Level *level;
    id message;
    NSString *renderedMessage;
    NSException *exception;
    NSCalendarDate *timestamp;

    char *rawFileName;
    char *rawMethodName;
    int   rawLineNumber;
    
    // NOTE: ALSO FOR NOW I'VE SKIPPED ALL OF THE NDC & MDC STUFF
}

+ (void) initialize;

+ (NSCalendarDate *) startTime;

+ (L4LoggingEvent *) logger: (L4Logger *) aLogger
                      level: (L4Level *) aLevel
                    message: (id) aMessage;

+ (L4LoggingEvent *) logger: (L4Logger *) aLogger
                      level: (L4Level *) aLevel
                    message: (id) aMessage
                  exception: (NSException *) e;

+ (L4LoggingEvent *) logger: (L4Logger *) aLogger
                      level: (L4Level *) aLevel
                 lineNumber: (int) aLineNumber
                   fileName: (char *) aFileName
                 methodName: (char *) aMethodName
                    message: (id) aMessage
                  exception: (NSException *) e;

- (id) initWithLogger: (L4Logger *) aLogger
                level: (L4Level *) aLevel
           lineNumber: (int) aLineNumber
             fileName: (char *) aFileName
           methodName: (char *) aMethodName
              message: (id) aMessage
            exception: (NSException *) e
       eventTimestamp: (NSDate *) aDate;

- (L4Logger *) logger;
- (L4Level *) level;

- (NSNumber *) lineNumber;
- (NSString *) fileName;
- (NSString *) methodName;

- (NSCalendarDate *) timestamp;
- (NSException *) exception;
- (long) millisSinceStart;
- (id) message;
- (NSString *) renderedMessage;

// DO WE NEED ACCESSOR METHODS FOR THE OTHER ELEMENT OF THE EVENT?

// - (NSString *) ndc;
// - (id) mdc: (NSString *) aKey;
// - (void) mdcCopy;

// - (NSString *) threadName;

// - (L4LocationInfo *) locationInformation;
// - (L4ThrowableInfo *) throwableInformation;
// - (NSString *) throwableStrRep;

// -------------------------------------------------------
// ### TODO - THESE ARE ALL PRIVATE METHODS take a look at NSCoder stuff
// -------------------------------------------------------
/*
- (void) readLevel: (INPUT_STREAM) ois;
- (void) readObject: (INPUT_STREAM) ois;
- (void) writeLevel: (OUTPUT_STREAM) oos;
- (void) writeObject: (OUTPUT_STREAM) oos;
*/
@end