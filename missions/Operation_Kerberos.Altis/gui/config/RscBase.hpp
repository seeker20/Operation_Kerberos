class RSC(BaseScrollbar) {
    color[] = {1,1,1,0.60000002};
    colorActive[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,0.30000001};
    thumb="\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
    arrowEmpty="\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
    arrowFull="\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
    border="\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
    shadow=0;
    scrollSpeed=0.059999999;
    width=0;
    height=0;
    autoScrollEnabled=0;
    autoScrollSpeed=-1;
    autoScrollDelay=5;
    autoScrollRewind=0;
};

class RSC(BaseControlsGroup) {
    type=15;
    idc=-1;
    x=0;
    y=0;
    w=1;
    h=1;
    shadow=0;
    style=16;
    class VScrollbar: RSC(BaseScrollbar) {
        width=0.021;
        autoScrollEnabled=1;
    };
    class HScrollbar: RSC(BaseScrollbar) {
        height=0.028000001;
    };
    class Controls {};
};
class RSC(BaseControlsGroupNoScrollbar) : RSC(BaseControlsGroup) {
    class VScrollbar: VScrollbar {
        width=0;
    };
    class HScrollbar: HScrollbar {
        height=0;
    };
};
class RSC(BaseControlsGroupNoHScrollbar) : RSC(BaseControlsGroup) {
    class HScrollbar: HScrollbar {
        height=0;
    };
};
class RSC(BaseControlsGroupNoVScrollbar) : RSC(BaseControlsGroup) {
    class VScrollbar: VScrollbar {
        width=0;
    };
};

class RSC(BaseStructuredText) {
    idc = -1;
    type = 13;  // defined constant
    style = 0x00;            // defined constant
    colorBackground[] = COLOR_BACKGROUND;
    size = GUI_TEXT_SIZE_MEDIUM;
    text = "";
    class Attributes {
        font = GUI_FONT_NORMAL;
        color = "#000000";
        align = "left";
        valign = "middle";
        shadow = 0;
        shadowColor = "#ff0000";
        size = 1;
    };
};


class RSC(BaseText) {
    idc = -1;
    type = 0;
    style = "0x00";
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    shadow = 0;
    colorShadow[] = COLOR_DISABLED;
    text = "";
    font = FONT_DEFAULT;
    colorText[] = COLOR_FONT;
    colorBackground[] = COLOR_BACKGROUND;
    /*
    tooltipColorText[] = COLOR_DISABLED;
    tooltipColorBox[] = COLOR_DISABLED;
    tooltipColorShade[] = COLOR_DISABLED;
    */
    tooltipColorText[] = COLOR_FONT;
    tooltipColorBox[] = COLOR_BACKGROUND;
    tooltipColorShade[] = COLOR_BACKGROUND;
    access = 0;
};
class RSC(BasePicture) : RSC(BaseText) {
    idc = -1;
    style = "48+0x800";
};

class RSC(BaseCheckBox) {
    idc=-1;
    type=77;
    style=0;
    checked=0;
    x="0.375 * safezoneW + safezoneX";
    y="0.36 * safezoneH + safezoneY";
    w="0.025 * safezoneW";
    h="0.04 * safezoneH";
    color[]={1,1,1,0.69999999};
    colorFocused[]={1,1,1,1};
    colorHover[]={1,1,1,1};
    colorPressed[]={1,1,1,1};
    colorDisabled[]={1,1,1,0.2};
    colorBackground[]={0,0,0,0};
    colorBackgroundFocused[]={0,0,0,0};
    colorBackgroundHover[]={0,0,0,0};
    colorBackgroundPressed[]={0,0,0,0};
    colorBackgroundDisabled[]={0,0,0,0};
    textureChecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    textureUnchecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
    textureFocusedChecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    textureFocusedUnchecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
    textureHoverChecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    textureHoverUnchecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
    texturePressedChecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    texturePressedUnchecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
    textureDisabledChecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    textureDisabledUnchecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
    tooltipColorText[]={1,1,1,1};
    tooltipColorBox[]={1,1,1,1};
    tooltipColorShade[]={0,0,0,0.64999998};
    soundEnter[]={"",0.1,1};
    soundPush[]={"",0.1,1};
    soundClick[]={"",0.1,1};
    soundEscape[]={"",0.1,1};
};

class RSC(BaseShortcut) {
    idc = -1;
    type = 1;
    style = "48+0x800";
    action = "";
    text = "";

    shadow = 0;
    font = FONT_DEFAULT;
    sizeEx = GUI_TAB_W * 1;

    colorBackground[] = COLOR_BACKGROUND;
    colorBackgroundActive[] = COLOR_BACKGROUND_FOCUSED;
    colorBackgroundDisabled[] = COLOR_DISABLED;
    colorBorder[] = COLOR_DISABLED;
    colorShadow[] = COLOR_DISABLED;

    colorDisabled[] = COLOR_SHORT_DISABLED;
    colorFocused[] = COLOR_SHORT_FOCUSED;
    colorText[] = COLOR_SHORT_TEXT;

    default = 0;

    x = GUI_TAB_X;
    y = GUI_TAB_Y;
    w = GUI_TAB_W * 7;
    h = GUI_TAB_H * 7;

    offsetPressedX = 0;
    offsetPressedY = 0;

    offsetX = 0;
    offsetY = 0;

    borderSize = 0;
    soundEnter[]= {};
    soundPush[]= {};
    soundClick[]= {};
    soundEscape[]= {};


};

class RSC(BaseShortcutButton) {
    idc=-1;
    type = 16;
    style=0;
    default=0;
    shadow=1;
    w=0.183825;
    h="(  (  ((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
    color[] = {1,1,1,1};
    colorFocused[] = {1,1,1,1};
    color2[] = {0.94999999,0.94999999,0.94999999,1};
    colorDisabled[] = {1,1,1,0.25};
    colorBackground[] = {
        "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
        1
    };
    colorBackgroundFocused[] = {
        "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
        1
    };
    colorBackground2[] = {1,1,1,1};
    textSecondary="";
    colorSecondary[] = {1,1,1,1};
    colorFocusedSecondary[] = {1,1,1,1};
    color2Secondary[] = {0.94999999,0.94999999,0.94999999,1};
    colorDisabledSecondary[] = {1,1,1,0.25};
    sizeExSecondary="( ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    fontSecondary="RobotoCondensed";
    animTextureDefault="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
    animTextureNormal="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
    animTextureDisabled="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
    animTextureOver="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\over_ca.paa";
    animTextureFocused="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\focus_ca.paa";
    animTexturePressed="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\down_ca.paa";
    periodFocus=1.2;
    periodOver=0.80000001;
    class HitZone {
        left=0;
        top=0;
        right=0;
        bottom=0;
    };
    class ShortcutPos {
        left=0;
        top="( (  (  ((safezoneW / safezoneH) min 1.2) / 1.2) / 20) -   ( ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
        w="( ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
        h="( ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    };
    class TextPos {
        left="( ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
        top="( (  (  ((safezoneW / safezoneH) min 1.2) / 1.2) / 20) -   ( ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
        right=0.0049999999;
        bottom=0;
    };
    period=0.40000001;
    shortcuts[] = {};
    textureNoShortcut = "#(argb,8,8,3)color(0,0,0,0)";
    font="RobotoCondensed";
    size="( ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    sizeEx="( ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    text="";
    soundEnter[] = {
        "\A3\ui_f\data\sound\RscButton\soundEnter",
        0.090000004,
        1
    };
    soundPush[] = {
        "\A3\ui_f\data\sound\RscButton\soundPush",
        0.090000004,
        1
    };
    soundClick[] = {
        "\A3\ui_f\data\sound\RscButton\soundClick",
        0.090000004,
        1
    };
    soundEscape[] = {
        "\A3\ui_f\data\sound\RscButton\soundEscape",
        0.090000004,
        1
    };
    action="";
    class Attributes {
        font="RobotoCondensed";
        color="#E5E5E5";
        align="left";
        shadow="true";
    };
    class AttributesImage {
        font="RobotoCondensed";
        color="#E5E5E5";
        align="right";
    };
};

class RSC(BaseObjectContainer) {
    idc = -1;
    type = 82;
    model = "";
    scale = 1;
    direction[] = {0, -0.35, -0.65};
    up[] = {0, 0.65, -0.35};
    //position[] = {0,0,0.2}; optional
    x = 0.5;
    y = 0.5;
    z = 0.2;
    //positionBack[] = {0,0,1.2}; optional
    xBack = 0.5;
    yBack = 0.5;
    zBack = 1.2;
    inBack = 1;
    enableZoom = 1;
    zoomDuration = 0.001;
};

class RSC(BaseSwitch) : RSC(BaseControlsGroup) {
    idc = -1;
    x = 0;
    y = 0;
    h = (GUI_TAB_W * 10);
    w = (GUI_TAB_W * 60);

    onMouseEnter = QUOTE([ARR_2(_this,'enter')] call FUNC(switch););
    onMouseExit = QUOTE([ARR_2(_this,'exit')] call FUNC(switch););
    onMouseButtonDown = QUOTE([ARR_2(_this,'click')] call FUNC(switch););

    style = 0;

    text_on = QPATHTOF(ui\switch_on.paa);
    text_off = QPATHTOF(ui\switch_on.paa);


    class VScrollbar {
        color[] = COLOR_DISABLED;
        width = 0;
        autoScrollSpeed = -1;
        autoScrollDelay = 0;
        autoScrollRewind = 0;
    };

    class HScrollbar {
        color[] = COLOR_DISABLED;
        height = 0;
    };

    class Controls {
        class background : RSC(BaseText) {
            idc = -1000;
            colorText[] = COLOR_DISABLED;
            x = 1;
            y = 1;
            w = 1;
            h = 1;
        };
        class slider : RSC(BasePicture) {
            idc = -1500;
            x = 0;
            y = 0.05;
            w = 0.2;
            h = 0.9;
        };
        class text : RSC(BaseText) {
            idc = -2000;
            x = 0.2;
            y = 0.05;
            w = 0.8;
            h = 0.9;
            sizeEx = 0.9;
            colorBackground[] = COLOR_DISABLED;
        };
    };
};

class RSC(BaseListbox) {
    access = 0;
    idc = 5;
    type = 5;
    style="0x00 + 0x10";
    default = 0;
    enable = 1;
    show = 1;
    fade = 0;
    blinkingPeriod = 0;
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    colorBackground[] = {0.2,0.2,0.2,1};
    colorSelectBackground[] = {1,0.5,0,1};
    colorSelectBackground2[] = {0,0,0,1};
    sizeEx = (pixelH * pixelGrid * 3);
    font = FONT_DEFAULT;
    shadow = 0;
    colorText[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,0.5};
    colorSelect[] = {1,1,1,1};
    colorSelect2[] = {1,1,1,1};
    colorShadow[] = {0,0,0,0.5};
    colorPicture[] = {1,0.5,0,1};
    colorPictureSelected[] = {1,1,1,1};
    colorPictureDisabled[] = {1,1,1,0.5};
    colorPictureRight[] = {1,0.5,0,1};
    colorPictureRightSelected[] = {1,1,1,1};
    colorPictureRightDisabled[] = {1,1,1,0.5};
    tooltip = "";
    tooltipColorShade[] = {0,0,0,1};
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    period = 1;
    rowHeight  =  (pixelH * pixelGrid * 4);
    itemSpacing = 0;
    maxHistoryDelay = 1;
    canDrag = 0;
    soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.090000004,1};
    class ListScrollBar {
        width = 0;
        height = 0;
        scrollSpeed = 0.0099999998;
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        color[] = {1,1,1,1};
    };
};

class RSC(BaseListboxN) {
    access = 0;
    type = 102;// 102;
    style = "0x10";
    font = GUI_FONT_NORMAL;
    sizeEx = (pixelH * pixelGrid * 3);
    colorText[] = COLOR_TABLET_MAIN_TEXT;
    colorBackground[] = {RAL9023,1};
    canDrag = false;

    autoScrollSpeed = -1;
    autoScrollDelay = 5;
    autoScrollRewind = 0;
    arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
    arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
    columns[] = {0.3, 0.6, 0.7};
    color[] = {RAL9023,1};
    colorScrollbar[] = {0.753,0.753,0.753,1};
    colorSelect[] = {RAL9023,1};
    colorSelect2[] = {RAL9023,1};
    colorDisabled[] = {RAL9023,1};
    colorSelectBackground[] = {0.863,0.863,0.863,1};
    colorSelectBackground2[] = {0.863,0.863,0.863,1};

    pictureColor[] = {RAL9023,1}; // Picture color
    pictureColorSelect[] = {0.301,0.301,0.301,1}; // Selected picture color
    pictureColorDisabled[] = {0.863,0.863,0.863,1}; // Disabled picture color

    drawSideArrows = 0;
    idcLeft = -1;
    idcRight = -1;
    maxHistoryDelay = 1;
    rowHeight = 0;
    soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
    period = 1;
    lineSpacing = 1;
    shadow = 0;
    class ScrollBar {
        arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
        arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
        border = "#(argb,8,8,3)color(1,1,1,1)";
        color[] = {RAL9023,1};
        colorActive[] = {0.863,0.863,0.863,1};
        colorDisabled[] = {0.863,0.863,0.863,1};
        thumb = "#(argb,8,8,3)color(1,1,1,1)";
    };
    class ListScrollBar {
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        autoScrollDelay = 5;
        autoScrollEnabled = 0;
        autoScrollRewind = 0;
        autoScrollSpeed = -1;
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        color[] = {RAL9023,1};
        colorActive[] = {0.863,0.863,0.863,1};
        colorDisabled[] = {0.863,0.863,0.863,1};
        height = 0;
        scrollSpeed = 0.06;
        shadow = 0;
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        width = 0;
    };
};

class RSC(BaseObject) {
    idc = -1;
    type = 82;
    movingEnable = false;    // true to enable moving dialog with mouse
    enableZoom = 0;
    zoomDuration = 0.001;
    inBack = 1;
    model = "\A3\Structures_F\Items\Food\Can_V3_F.p3d";
    direction[] = {0,0.5,0.5};
    up[] = {0,1,0};
    scale = "0.47 * 0.875 * (SafeZoneW Min SafeZoneH)";
    xBack = 0.5;
    yBack = 0.5;
    zBack = 1.2;
    // x and y are the position on the screen.
    // current x and y put the top left corner of the object into the top left corner of the screen.
    // Use z in addition to scale to fine tune the size/ zoom of the object
    x = (0 * safezoneW + safezoneX);
    y = (0 * safezoneH + safezoneY);
    z = 2;
};

class RSC(BaseButton) {
    access = 0;
    type = 1;
    style = "0x02";
    text = "";
    font = GUI_FONT_NORMAL;
    sizeEx = GUI_GRID_CENTER_H;
    colorText[] = COLOR_TABLET_MAIN_BTTN_TEXT;
    colorDisabled[] = COLOR_DISABLED;
    colorBackground[] = COLOR_TABLET_MAIN_BTTN;
    colorBackgroundActive[] = COLOR_TABLET_MAIN_BTTN_SELECTED;
    colorFocused[] = COLOR_TABLET_MAIN_BTTN_TEXT_SELECTED;
    colorBackgroundDisabled[] = COLOR_DISABLED;
    offsetX = 0.004;
    offsetY = 0.004;
    offsetPressedX = 0.002;
    offsetPressedY = 0.002;
    colorShadow[] = {0,0,0,1};
    shadow = 0;
    colorBorder[] = {0,0,0,1};
    borderSize = 0;
    soundEnter[] = {"",0.1,1};
    soundPush[] = {"",0.1,1};
    soundClick[] = {"",0.1,1};
    soundEscape[] = {"",0.1,1};
    onButtonClick = "";
};

class RSC(BaseXButton) {
    access=0;
    idc=41;
    type=41;
    style=0;
    default=0;
    enable=1;
    show=1;
    fade=0;
    blinkingPeriod=0;
    x="12 *                     (            ((safezoneW / safezoneH) min 1.2) / 40) +         (safezoneX + (safezoneW -                     ((safezoneW / safezoneH) min 1.2))/2)";
    y="15 *                     (            (            ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) +         (safezoneY + (safezoneH -                     (            ((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
    w="10 *                     (            ((safezoneW / safezoneH) min 1.2) / 40)";
    h="1 *                     (            (            ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    colorBackground[] = {0,0,0,0};
    colorActiveBackground[] = {1,0.5,0,1};
    colorActiveBackground2[] = {0,0,0,1};
    colorDisabled[] = {0,1,1,1};
    text="CT_XBUTTON";
    size="(            (            ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    font="RobotoCondensed";
    shadow=0;
    color[] = {1,1,1,1};
    colorActive[] = {1,1,1,1};
    colorActive2[] = {1,1,1,1};
    tooltip="CT_XBUTTON";
    tooltipColorShade[] = {0,0,0,1};
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    period=1;
    soundClick[]=
    {
        "\A3\ui_f\data\sound\RscButton\soundClick",
        0.090000004,
        1
    };
    soundEnter[]=
    {
        "\A3\ui_f\data\sound\RscButton\soundEnter",
        0.090000004,
        1
    };
    soundPush[]=
    {
        "\A3\ui_f\data\sound\RscButton\soundPush",
        0.090000004,
        1
    };
    soundEscape[]=
    {
        "\A3\ui_f\data\sound\RscButton\soundEscape",
        0.090000004,
        1
    };
};

class RSC(BaseEditBox) {
    access = 0;
    type = 2;
    style = "0x40+0x00";
    colorBackground[] = COLOR_TABLET_BACKGROUND;
    colorText[] = COLOR_TABLET_MAIN_TEXT;
    colorSelection[] = COLOR_TABLET_MAIN_TEXT;
    colorDisabled[] = COLOR_TABLET_BACKGROUND;
    font = GUI_FONT_NORMAL;
    sizeEx = IGUI_TEXT_SIZE_MEDIUM;
    autocomplete = "";
    text = "";
    size = IGUI_TEXT_SIZE_MEDIUM;
    shadow = 0;
};

class RSC(BaseEdit) {
    type = 2;
    style="0x00 + 0x40";
    font=GUI_FONT_NORMAL;
    text = "";
    autocomplete = "";
    shadow=0;
    sizeEx = (pixelH * pixelGrid * 3);
    colorBackground[]={0,0,0,0};
    colorText[]={0.94999999,0.94999999,0.94999999,1};
    colorDisabled[]={1,1,1,0.25};
    colorSelection[]={"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",1};
    canModify=1;
    tooltipColorText[]={1,1,1,1};
    tooltipColorBox[]={1,1,1,1};
    tooltipColorShade[]={0,0,0,0.64999998};
};


class RSC(BaseCombobox) {
    access = 0;
    type = 4;
    style = 0x00;
    h = 0.05;
    wholeHeight = 0.25;
    colorSelect[] = {0.6,0.6,0.6,1};
    colorText[] = {1,1,1,1};
    colorBackground[] = {0.2,0.2,0.2,1};
    colorScrollbar[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,0.5};
    font = "TahomaB";
    sizeEx = 0.04;
    soundSelect[] = {"",0.1,1};
    soundExpand[] = {"",0.1,1};
    soundCollapse[] = {"",0.1,1};
    maxHistoryDelay = 1.0;
    shadow = 0;
    arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
    arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow
    class ComboScrollBar {
        color[] = {1,1,1,0.6};
        colorActive[] = {1,1,1,1};
        colorDisabled[] = {1,1,1,0.3};
        thumb = "#(argb,8,8,3)color(1,1,1,1)";
        arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
        arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
        border = "#(argb,8,8,3)color(1,1,1,1)";
        shadow = 0;
    };
};

class RSC(BaseTree) {
    idc = -1;
    type = 12;
    style = 0;
    default = 0;
    enable = 1;
    show = 1;
    fade = 0;
    blinkingPeriod = 0;
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    rowHeight=0.043909099;
    sizeEx = (pixelH * pixelGrid * 3);
    font = FONT_DEFAULT;
    shadow = 0;

    colorDisabled[] = COLOR_DISABLED; // not used
    colorArrow[] = COLOR_DISABLED; // not used

    borderSize=0;
    colorBorder[] = COLOR_DISABLED;
    colorLines[]={0,0,0,0};

    colorBackground[] = {0.2,0.2,0.2,1};
    colorText[] = {1,1,1,1};

    colorSelectBackground[]={0,0,0,0.5};
    colorSelectText[] = {1,1,1,1};
    colorSelect[] = {1,0.5,0,1};

    colorMarked[] = {1,0.5,0,0.5};
    colorMarkedSelected[] = {1,0.5,0,1};
    colorMarkedText[] = {1,1,1,1};

    colorPicture[]={1,1,1,1};
    colorPictureSelected[]={0,0,0,1};
    colorPictureDisabled[]={1,1,1,0.25};
    colorPictureRight[]={1,1,1,1};
    colorPictureRightSelected[]={0,0,0,1};
    colorPictureRightDisabled[]={1,1,1,0.25};

    colorSearch[]={
        "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
    };

    tooltip = "";
    tooltipColorShade[] = {0,0,0,1};
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    multiselectEnabled = 1;
    expandOnDoubleclick = 1;
    hiddenTexture = "A3\ui_f\data\gui\rsccommon\rsctree\hiddenTexture_ca.paa";
    expandedTexture = "A3\ui_f\data\gui\rsccommon\rsctree\expandedTexture_ca.paa";
    maxHistoryDelay = 1;
    disableKeyboardSearch = 1;
    class ScrollBar {
        width = 0;
        height = 0;
        scrollSpeed = 0.0099999998;
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        color[] = {1,1,1,1};
    };
};

class RSC(BaseLoadingbar) {
    type = 8;
    style = 0;
    colorFrame[] = UI_CL_CTRL_GRAU4;
    colorBar[] = UI_CL_CTRL_GRAU2;
    texture = "#(argb,8,8,3)color(1,1,1,1)";
    w = 1;
    h = 0.03;
};

#define NOISE(NUMBER) class strip##NUMBER : stripe1 {idc = IDC_LOADING_NOISE0##NUMBER ;}
#define NOISEW(NUMBER) class strip##NUMBER : stripe1 {idc = IDC_LOADING_NOISE0##NUMBER ;colorBackground[] = {ARR_2(RAL9010,0.35)};}

class RSC(BaseNoise) : RSC(BaseControlsGroupNoScrollbar) {
    idc = IDC_LOADING_NOISE;
    x = "safezoneXAbs";
    y = "safezoneY";
    w = "safezoneWAbs";
    h = "safezoneH";
    class controls {
        class stripe1 : RSC(BaseText) {
            idc = IDC_LOADING_NOISE1;
            x = 0;
            y = 0;
            w = 0;
            h = 0;
            colorBackground[] = {RAL9004,0.35};
        };
        NOISE(01);
        NOISE(02);
        NOISE(03);
        NOISE(04);
        NOISE(05);
        NOISE(06);
        NOISE(07);
        NOISE(08);
        NOISE(09);
        NOISE(10);
        NOISE(11);
        NOISE(12);
        NOISE(13);
        NOISE(14);
        NOISE(15);
        NOISE(16);
        NOISE(17);
        NOISE(18);
        NOISE(19);
        NOISE(20);
        NOISE(21);
        NOISE(22);
        NOISE(23);
        NOISE(24);
        NOISE(25);
        NOISE(26);
        NOISE(27);
        NOISE(28);
        NOISE(29);
        NOISEW(30);
        NOISEW(31);
        NOISEW(32);
        NOISEW(33);
        NOISEW(34);
        NOISEW(35);
        NOISEW(36);
        NOISEW(37);
        NOISEW(38);
        NOISEW(39);
        NOISEW(40);
        NOISEW(41);
        NOISEW(42);
        NOISEW(43);
        NOISEW(44);
        NOISEW(45);
        NOISEW(46);
        NOISEW(47);
        NOISEW(48);
        NOISEW(49);
        NOISEW(50);
    };
};

class RSC(loadingScreen) {
    idd = IDD_LOADING;
    onLoad = QUOTE(_this call FUNC(onLoadLoadingScreen););
    class controlsBackground {
        class black : RSC(BaseText) {
            colorBackground[] = COLOR_LOADING_BACKGROUND;
            x = safezoneXAbs;
            y = safezoneY;
            w = safezoneWAbs;
            h = safezoneH;
        };
    };
    class controls {
        class noise : RSC(BaseNoise) {};
        class progress : RSC(BaseLoadingbar) {
            idc = IDD_LOADING_PROGRESS;
            x = GUI_GRID_CENTER_X + GUI_GRID_CENTER_W * 12;
            y = GUI_GRID_CENTER_Y + GUI_GRID_CENTER_H * 25;
            w = GUI_GRID_CENTER_W * 16;
            h = GUI_GRID_CENTER_H * 1;
            colorFrame[] = COLOR_LOADING_PROGRESS;
            colorBar[] = COLOR_LOADING_PROGRESSFRAME;
            texture = "#(argb,8,8,3)color(0.34,0.65,0.22,1)";
        };
        class backgroundcircle : RSC(BasePicture) {
            colorBackground[] = COLOR_LOADING_BACKGROUND;
            colorText[] = COLOR_LOADING_CIRCLEIN;
            x = GUI_GRID_CENTER_X + GUI_GRID_CENTER_W * 10;
            y = GUI_GRID_CENTER_Y + GUI_GRID_CENTER_H * 5;
            w = GUI_GRID_CENTER_W * 20;
            h = GUI_GRID_CENTER_H * 20;
            text = QPAAPATH(loading_backIn);
        };
        class circle : backgroundcircle {
            idc = IDD_LOADING_CIRCLE;
            colorText[] = COLOR_LOADING_CIRCLE;
            text = QPAAPATH(loading_circle);
        };
        class backgroundLogo : backgroundcircle {
            x = GUI_GRID_CENTER_X + GUI_GRID_CENTER_W * 13;
            y = GUI_GRID_CENTER_Y + GUI_GRID_CENTER_H * 8;
            w = GUI_GRID_CENTER_W * 14;
            h = GUI_GRID_CENTER_H * 14;
            colorBackground[] = COLOR_LOADING_BACKGROUND;
            colorText[] = COLOR_LOADING_LOGO;
            text = QEPAAPATH(logo,logo_512w);
        };
        class title : RSC(BaseText) {
            idc = IDD_LOADING_TITLE;
            colorText[] = COLOR_LOADING_TITLE;
            colorBackground[] = COLOR_DISABLED;
            x = GUI_GRID_CENTER_X;
            y = GUI_GRID_CENTER_Y;
            w = GUI_GRID_CENTER_W * 40;
            h = GUI_GRID_CENTER_H * 5;
            style = 0x02;
            text = "L o a d i n g  . . .";
            sizeEx = GUI_GRID_CENTER_H * 4;
            font = FONT_THIN;
        };
        class description : RSC(BaseText) {
            idc = IDD_LOADING_DESCRIPTION;
            colorText[] = COLOR_LOADING_TITLE;
            colorBackground[] = COLOR_DISABLED;
            x = GUI_GRID_CENTER_X + GUI_GRID_CENTER_W * 12;
            y = GUI_GRID_CENTER_Y + GUI_GRID_CENTER_H * 25;
            w = GUI_GRID_CENTER_W * 16;
            h = GUI_GRID_CENTER_H * 1;
            sizeEx = GUI_GRID_CENTER_H * 0.92;
            //font = FONT_BOLD;
            style = 0x02;
            text = "";
        };
    };
};

class RSC(BaseActiveText) {
    idc = -1;
    type = 11;
    style = "0x00";
    x=0;
    y=0;
    h=0.035;
    w=0.035;

    font = GUI_FONT_NORMAL;
    shadow = 2;
    sizeEx = "(            (            (            ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    url = "";
    color[] = {RAL9005,1};
    colorActive[] = {RAL6018,1};
    colorShade[] = {RAL6018,1};
    colorFocused[] = {RAL6018,1};
    colorDisabled[] = {RAL9005,0.25};
    colorText[] = {RAL9010,1};

    text = "blubb";
    colorBackground2[] = {RAL4010,1};
    picture = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayersetup\flag_bluefor_empty_ca.paa";


    sideToggle = "a3\ui_f\data\gui\rsc\rscdisplaymultiplayersetup\flag_bluefor_ca.paa";
    sideDisabled = "a3\ui_f\data\gui\rsc\rscdisplaymultiplayersetup\flag_none_ca.paa";
    pictureHeight = 1;
    pictureWidth = 1;

    tooltipColorText[] = {RAL9005,1};
    tooltipColorBox[] = {RAL9005,1};
    tooltipColorShade[] = {RAL9004,0.64999998};
    action = "";
    candrag = 1;
    blinkingPeriod = 0.2;

    soundEnter[] = {"",0.1,1};
    soundPush[] = {"",0.1,1};
    soundClick[] = {"",0.1,1};
    soundDoubleClick[] = {"",0.1,1};
    soundEscape[] = {"",0.1,1};
};

class RSC(ControlsTable) {
    idc = 107;
    x = SafezoneX + 16.5 * GUI_GRID_W;
    y = SafezoneY + 3.5 * GUI_GRID_H;
    w = 15 * GUI_GRID_W;
    h = 20 * GUI_GRID_H;

    type = 19;
    style = 0x10;

    lineSpacing = 0;
    rowHeight = 1 * GUI_GRID_H;
    headerHeight = 1 * GUI_GRID_H;

    firstIDC = 42000;
    lastIDC = 44999;

    // Colours which are used for animation (i.e. change of colour) of the selected line.
    selectedRowColorFrom[]  = {0.7, 0.85, 1, 0.25};
    selectedRowColorTo[]    = {0.7, 0.85, 1, 0.5};
    // Length of the animation cycle in seconds.
    selectedRowAnimLength = 1.2;

    class VScrollBar: RSC(BaseScrollbar) {
        width = 0.021;
        autoScrollEnabled = 0;
        autoScrollDelay = 1;
        autoScrollRewind = 1;
        autoScrollSpeed = 1;
    };

    class HScrollBar: RSC(BaseScrollbar) {
        height = 0.028;
    };

    // Template for selectable rows
    class RowTemplate {
        class RowBackground {
            controlBaseClassPath[] = {"RscText"};
            columnX = 0;
            columnW = 14.7 * GUI_GRID_W;
            controlOffsetY = 0;
        };
        class Column1 {
            controlBaseClassPath[] = {"RscPictureKeepAspect"};
            columnX = 0;
            columnW = 2 * GUI_GRID_W;
            controlOffsetY = 0;
            controlH = 1 * GUI_GRID_H;
        };
        class Column2 {
            controlBaseClassPath[] = {"RscText"};
            columnX = 2 * GUI_GRID_W;
            columnW = 8.7 * GUI_GRID_W;
            controlOffsetY = 0.1 * GUI_GRID_H;
        };
        class Column3 {
            controlBaseClassPath[] = {"RscButton"};
            columnX = 11.2 * GUI_GRID_W;
            columnW = 2 * GUI_GRID_W;
            controlOffsetY = 0.1 * GUI_GRID_H;
        };
    };

    // Template for headers (unlike rows, cannot be selected)
    class HeaderTemplate {
        class HeaderBackground {
            controlBaseClassPath[] = {"RscText"};
            columnX = 0;
            columnW = 14.7 * GUI_GRID_W;
            controlOffsetY = 0;
        };
        class Column1 {
            controlBaseClassPath[] = {"RscPictureKeepAspect"};
            columnX = 0.2 * GUI_GRID_W;
            columnW = 0.6 * GUI_GRID_W;
            controlOffsetY = 0.2 * GUI_GRID_H;
            controlH = 0.6 * GUI_GRID_H;
        };
        class Column2 {
            controlBaseClassPath[] = {"RscText"};
            columnX = 0.8 * GUI_GRID_W;
            columnW = 9 * GUI_GRID_W;
            controlOffsetY = 0.1 * GUI_GRID_H;
        };
    };
};
