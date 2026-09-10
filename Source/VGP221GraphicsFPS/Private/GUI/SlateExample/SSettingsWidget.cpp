// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/SlateExample/SSettingsWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSettingsWidget::Construct(const FArguments& InArgs)
{
    // Title Settings
    const FText TitleText = FText::FromString("Settings Screen");
    FSlateFontInfo TitleFontInfo = FCoreStyle::Get().GetFontStyle("EmbassedText");
    TitleFontInfo.Size = 60;

    ChildSlot
        [
            // Populate the widget
            SNew(SOverlay)
                + SOverlay::Slot()
                .HAlign(HAlign_Fill)
                .VAlign(VAlign_Fill)
                [
                    SNew(SImage)
                        .ColorAndOpacity(FLinearColor::Black)
                ]
                + SOverlay::Slot()
                .HAlign(HAlign_Fill)
                .VAlign(VAlign_Fill)
                [
                    SNew(SVerticalBox)
                        + SVerticalBox::Slot()
                        [
                            SNew(STextBlock)
                                .Text(TitleText)
                                .Font(TitleFontInfo)
                                .Justification(ETextJustify::Center)
                        ]
                ]
        ];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
