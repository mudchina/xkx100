// /d/xiakedao/shiroom21.c 侠客岛 石室21

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
进门便觉精神一振，原来上方有一尺许见方的通风孔，不似其他
石室那般气闷。一抹阳光从孔中透入，投在对面的石壁(wall)上。隐
隐也能听见外面的鸟雀叽嚓飞过，令人片刻间神游物外。
LONG );
        set("exits", ([
                "south" : __DIR__"shihole6",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「纵死侠骨香」几个大字。下面绘的是春秋时另一个
惨烈的故事「要离刺庆忌」。那要离身材既矮，且又独臂，但一股杀
气直是摄人魂魄。一行注云：韩昌黎诗：想当施手时，巨刃摩天扬。
又注：叱咤则风云变色。
WALL
        ]));
        set("objects", ([
                __DIR__"master/miejue" : 1,
                __DIR__"master/zhou"   : 1,
        ]));
/*
周芷若说道：徒儿定会紧记与心的。

周芷若一式「闪现雷鸣」，左掌外旋上挑，右指内翻前指，闪点般急点灭绝师太的左脸！
结果被灭绝师太挡开了。

周芷若一式「闪现雷鸣」，左掌外旋上挑，右指内翻前指，闪点般急点灭绝师太的后心！
结果只听见灭绝师太一声惨嚎，指力已在灭绝师太的后心对穿而出，鲜血溅得满地！！
( 灭绝师太受伤不轻，看起来状况并不太好。 )
周芷若说道：这一句是否指出掌必尽全力，伤敌无虑
*/
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
	set("coor/x", -3090);
	set("coor/y", -25590);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"