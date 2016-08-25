//
//  singleton.h
//  单例讲解
//
//  Created by jredu on 16/8/25.
//  Copyright © 2016年 jereh. All rights reserved.
//

#define singleton_h(name) + (instancetype) share##name



#if __has_feature(objc_arc)

#define singleton_m(name)\
\
static id  instance;\
+(instancetype)allocWithZone:(struct _NSZone *)zone{\
    \
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        if (instance==nil) {\
            instance= [super allocWithZone:zone];\
        }\
    });\
    \
    return instance;\
    \
}\
\
+ (id)copyWithZone:(struct _NSZone *)zone{\
    return  [self allocWithZone:zone];\
}\
\
+ (id)mutableCopyWithZone:(struct _NSZone *)zone{\
    \
    return  [self allocWithZone:zone];\
}\
\
\
+ (instancetype) share##name{\
    \
    return [self alloc];\
}

#else

#define singleton_m(name)\
\
static id  instance;\
+(instancetype)allocWithZone:(struct _NSZone *)zone{\
\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
if (instance==nil) {\
instance= [super allocWithZone:zone];\
}\
});\
\
return instance;\
\
}\
\
+ (id)copyWithZone:(struct _NSZone *)zone{\
return  [self allocWithZone:zone];\
}\
\
+ (id)mutableCopyWithZone:(struct _NSZone *)zone{\
\
return  [self allocWithZone:zone];\
}\
\
\
+ (instancetype) share##name{\
\
return [self alloc];\
}\
\
-(oneway void)release{\
    \
}\
\
-(instancetype)retain{\
    return  instance;\
}\
\
\
-(instancetype)autorelease{\
    return instance;\
}\
\
-(NSUInteger)retainCount{\
    \
    return 1;\
}

#endif

