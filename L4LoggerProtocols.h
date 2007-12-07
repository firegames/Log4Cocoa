/**
 * For copyright & license, see COPYRIGHT.txt.
 */

#import <Foundation/Foundation.h>
@class L4Logger, L4Level, L4RendererMap;


@protocol L4LoggerFactory

- (L4Logger *) makeNewLoggerInstance: (NSString *) aName;

@end


@protocol L4LoggerRepository <NSObject>

/**
Is the repository disabled for a given level? The answer depends
on the repository threshold and the <code>level</code>
parameter. See also {@link #setThreshold} method.  */

- (BOOL) isDisabled: (int) aLevel;
- (L4Logger *) exists: (id) loggerNameOrLoggerClass;

- (L4Level *) threshold;
- (void) setThreshold: (L4Level *) aLevel;
- (void) setThresholdByName: (NSString *) aLevelName;

- (L4Logger *) rootLogger;
- (L4Logger *) loggerForClass: (Class) aClass;
- (L4Logger *) loggerForName: (NSString *) aName;
- (L4Logger *) loggerForName: (NSString *) aName
                     factory: (id <L4LoggerFactory>) aFactory;

- (NSArray *) currentLoggersArray;
- (NSEnumerator *) currentLoggers;

- (void) emitNoAppenderWarning: (L4Logger *) aLogger;

- (void) resetConfiguration;
- (void) shutdown;

@end


@protocol L4RepositorySelector <NSObject>

- (id <L4LoggerRepository>) loggerRepository;

@end

