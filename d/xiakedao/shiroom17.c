// /d/xiakedao/shiroom17.c 侠客岛 石室17

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
这里铿锵之声不绝，一个身材矮小的汉子手持黄金棍，与使蛾眉
刺的少妇双战一个瘦子。那瘦子在一片黄光中身形晃动，丝毫不落下
风。兵刃劲风激荡之下，火把也熄灭了两支。石壁(wall)上的图谱隐
约可见。
LONG );
        set("exits", ([
                "south" : __DIR__"shihole5",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「救赵挥金槌」几个大字。下面的图画波澜壮阔，豪
气逼人。正是岳武穆大破金兵，八大锤闹朱仙镇。只见刀枪蔽日，血
肉横飞。旁边注释不多，均是笔力雄健。
WALL
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
	set("coor/x", -3090);
	set("coor/y", -25490);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"