//
//  ViewController.m
//  MGMacro
//
//  Created by Mingle on 2018/4/9.
//  Copyright © 2018年 Mingle. All rights reserved.
//

#import "ViewController.h"
#import "MGMacro.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    NSLog(@"%@", @(MGNAV_ADD_STATUS_HEIGHT));
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
