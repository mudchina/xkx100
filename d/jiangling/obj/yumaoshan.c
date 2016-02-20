//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;
int do_play(string arg);

//void setup()
//{}

void init()
{
        add_action("do_shan", "shan");
}

void create()
{
        set_name(HIW"羽毛扇"NOR, ({"yumaoshan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把洪湖羽毛扇。这种扇子选用各种鸟禽之翅、尾毛，按羽毛的色泽
纹理，制成扇面，然后配竹蔑、牛骨、象牙等作为扇骨，扇尾还吊一根丝
线结坠。民间又称之为孔明扇。你可以扇扇(shan)它。\n");
                set("value", 300);
        }
//        setup();
}

int do_shan(string arg)
{
        if (!id(arg))
                return notify_fail("你要扇什么？\n");
        switch( random(2) ) {
                case 0:
                        say(this_player()->name() + "拿起羽毛扇，悠闲自得地扇了扇，颇得孔明的遗风呢。\n");
			write(this_player()->name() + "拿起羽毛扇，悠闲自得地扇了扇，颇得孔明的遗风呢。\n");

                        break;
                case 1:
                        say(this_player()->name() + "一边摇着羽毛扇，一边抑扬顿挫地吟着：羽扇纶巾，数千古风流人物，咱也算一个。\n");
			write(this_player()->name() + "一边摇着羽毛扇，一边抑扬顿挫地吟着：羽扇纶巾，数千古风流人物，咱也算一个。\n");

                        break;
        }
        return 1;
}

