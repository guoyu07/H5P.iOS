//
//  QBImagePickerController.h
//  QBImagePickerController
//
//  Created by Tanaka Katsuma on 2013/12/30.
//  Copyright (c) 2013年 Katsuma Tanaka. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AssetsLibrary/AssetsLibrary.h>

typedef NS_ENUM(NSUInteger, QBImagePickerControllerFilterType) {
    QBImagePickerControllerFilterTypeNone,
    QBImagePickerControllerFilterTypePhotos,
    QBImagePickerControllerFilterTypeVideos
};

UIKIT_EXTERN ALAssetsFilter * ALAssetsFilterFromQBImagePickerControllerFilterType(QBImagePickerControllerFilterType type);

@class QBImagePickerController;

@protocol QBImagePickerControllerDelegate <NSObject>

@optional
- (void)imagePickerController:(QBImagePickerController *)imagePickerController didSelectAsset:(ALAsset *)asset;
- (void)imagePickerController:(QBImagePickerController *)imagePickerController didSelectAssets:(NSArray *)assets;
- (void)imagePickerControllerDidCancel:(QBImagePickerController *)imagePickerController;
- (void)assetsCollectionViewControllerOnmaxed:(QBImagePickerController *)assetsCollectionViewController;
@end

@interface QBImagePickerController : UITableViewController

@property (nonatomic, strong, readonly) ALAssetsLibrary *assetsLibrary;
@property (nonatomic, copy, readonly) NSArray *assetsGroups;
@property (nonatomic, strong, readonly) NSMutableArray *selectedAssetURLs;

@property (nonatomic, weak) id<QBImagePickerControllerDelegate> delegate;
@property (nonatomic, copy) NSArray *groupTypes;
@property (nonatomic, assign) QBImagePickerControllerFilterType filterType;
@property (nonatomic, assign) BOOL showsCancelButton;
@property (nonatomic, assign) BOOL allowsMultipleSelection;
@property (nonatomic, assign) NSUInteger minimumNumberOfSelection;
@property (nonatomic, assign) NSUInteger maximumNumberOfSelection;
@property (nonatomic, assign) BOOL allowsAllSelection;
+ (BOOL)isAccessible;
- (BOOL)validateNumberOfSelections:(NSUInteger)numberOfSelections;
- (void)setDefalutSelectedAssetURLs:(NSArray *)selectedAssetURLs;
@end
