// /d/xiakedao/shiroom08.c 侠客岛 石室8

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
石洞正中，一位白眉僧人和一位青袍之人正比试武功。一对男女
在旁边并肩奔行，趋退之际，步法配合甚是和谐。另有一人神色不屑
地站在墙角，边指点石壁(wall)，边指摘众人的招式。
LONG );
        set("exits", ([
                "east" : __DIR__"shihole2",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「深藏身与名」几个大字。字的下方刻的是一个脍炙
人口的故事：范蠡与西施功成身退，泛舟湖上。只见图中美女星目含
情，旁边是范大夫微笑不语。舟下的水纹荡漾，与远方天色连成一体。
WALL
        ]));
        set("objects", ([
                __DIR__"master/huang" : 1,
                __DIR__"master/yideng" : 1,
        ]));
/*
一灯大师哈哈大笑，对着黄药师拱了拱手道：老爷子过奖了!
一灯大师说道：劲力内含，发之无形，伤人与不觉之中。

一灯大师“嚯”地冲到黄药师的跟前，左手无名指一反一复连点两下，旋即退开，正是一式
「阴阳交错」！
黄药师身形疾闪，使出一招“海燕腾空”，身体如同为海风所激，向后飘开一丈有余，避过
一灯大师攻击。

一灯大师身形陡然向上拔起，双手急点数下，一式「烈日骄阳」已将黄药师的全身要穴罩在
指风之下！
黄药师身形疾闪，使出一招“海燕腾空”，身体如同为海风所激，向后飘开一丈有余，避过
一灯大师攻击。
*/
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
	set("coor/x", -3100);
	set("coor/y", -25200);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"