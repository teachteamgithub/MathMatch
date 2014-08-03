//
//  MMXGameViewController.h
//  MathMatch
//
//  Created by Kyle O'Brien on 2014.1.25.
//  Copyright (c) 2014 Computer Lab. All rights reserved.
//

#import "KMODecisionView.h"
#import "MMXCardViewController.h"

@class MMXGameViewController;
@class MMXHowToPlayDelegate;

@protocol MMXGameDelegate <NSObject>

- (void)advanceTutorialForGameViewController:(MMXGameViewController *)gameViewControlller;

@end

@interface MMXGameViewController : UIViewController <KMODecisionViewDelegate, MMXCardViewControllerDelegate>

typedef NS_ENUM(NSUInteger, MMXGameState)
{
    MMXGameStatePreGame,
    MMXGameStateStarted,
    MMXGameStateNoCardsFlipped,
    MMXGameStateOneCardFlipped,
    MMXGameStateTwoCardsFlipped,
    MMXGameStateAnimating,
    MMXGameStateOver
};

@property (nonatomic, strong) NSManagedObjectContext *managedObjectContext;

@property (nonatomic, strong) MMXGameData *gameData;
@property (nonatomic, strong) MMXHowToPlayDelegate *howToPlayDelegate;

@property (nonatomic, strong) NSArray *manuallySpecifiedCardValues;

@property (nonatomic, strong) IBOutlet UIBarButtonItem *pauseBarButtonItem;

@property (nonatomic, weak) IBOutlet UIView *equationContainerView;
@property (nonatomic, weak) IBOutlet UIView *equationCorrectnessView;

@property (nonatomic, weak) IBOutlet UILabel *xNumberLabel;
@property (nonatomic, weak) IBOutlet UILabel *yNumberLabel;
@property (nonatomic, weak) IBOutlet UILabel *zNumberLabel;
@property (nonatomic, weak) IBOutlet UILabel *aFormulaLabel;
@property (nonatomic, weak) IBOutlet UILabel *bFormulaLabel;

@property (nonatomic, strong) NSMutableArray *cardsList;

- (IBAction)playerTappedPauseButton:(id)sender;
- (IBAction)unwindToGame:(UIStoryboardSegue *)unwindSegue;

- (void)arrangDeckOntoTableauAndStartDealing;

@end
