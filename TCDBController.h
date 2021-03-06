//
//  TCDBController.h
//  TranslationCards
//
//  Created by Баз Светик on 28.08.13.
//  Copyright (c) 2013 SS United. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCDictionariesModel.h"
#import "TCLanguagesModel.h"
#import "TCProfileModel.h"
#import "TCWordsModel.h"

@interface TCDBController : NSObject{
    NSPersistentStoreCoordinator *persistentStoreCoordinator;
    NSManagedObjectModel *managedObjectModel;
    NSManagedObjectContext *managedObjectContext;
    
}
@property (nonatomic, retain, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;

@property (nonatomic, retain) TCProfileModel *currentProfile;
@property (nonatomic, retain) TCDictionariesModel *currentDictionary;

- (void) delAll;
- (NSArray*) getAllDictionaries;
- (NSArray*) getAllWords;
- (TCWordsModel*)getLastWord;

//управление профилем
- (void)addProfile:(NSString *)name;
- (void)delProfile:(TCProfileModel*)profile;
- (void)updateProfile:(TCProfileModel*)profile;
- (void)setCurrentProfile:(TCProfileModel*)profile;
- (NSArray*)getProfiles;

//управление словарями
- (void)addDictionary:(NSString*)name;
- (void)delDictionary:(TCDictionariesModel*)dictionary;
- (void)updateDictionary:(TCDictionariesModel*)dictionary;
- (void)setCurrentDictionary:(TCDictionariesModel*)dictionary;
- (NSArray*)getDictionaries;

//управление перечнем языков
- (void)addLanguage:(NSString*)name;
- (void)delLanguage:(TCLanguagesModel*)language;
- (void)updateLanguage:(TCLanguagesModel*)language withNewName:(NSString*)newName;
- (NSArray*)getLanguages;

//управление перечнем слов
- (void)addWord:(NSString*)name withTranslation:(NSString*)translation withOtherForms:(NSString*)otherForm;
- (void)delWord:(TCWordsModel*)word;
- (void)updateWord:(TCWordsModel*)word withName:(NSString*)name withTranslation:(NSString*)translation withOtherForms:(NSString*)otherForms;
- (NSArray*)getWords;

@end
