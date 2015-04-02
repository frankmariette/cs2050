//
//  SimpleTableDetailViewController.h
//  Test
//
//  Created by Francois Mariette on 1/24/14.
//  Copyright (c) 2014 Francois Mariette. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SimpleTableDetailViewController : UIViewController

@property (strong, nonatomic) id detailItem;

@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;
@end
