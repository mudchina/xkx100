// /d/xiakedao/shiroom01.c 侠客岛 石室1

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
这是第一间石室。不少人走来走去，已经颇为拥挤。那些人有的
注目凝思，有的打坐练功，有的闭目喃喃自语，更有的正在大声争辩。
东面是块打磨光滑的大石壁(wall)，石壁旁点燃着火把，把整间石室
照耀得白昼相仿。
LONG );
        set("exits", ([
                "south" : __DIR__"shihole1",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「赵客缦胡缨」几个大字。字的下方刻着一幅图，图
中是一个书生，他左手持扇，右手飞掌，神态甚是优雅潇洒……旁有
一行注解云：须从威猛刚硬处着手。另有无数小字，密密麻麻。
WALL
        ]));
        set("objects", ([
                __DIR__"master/xuedao"   : 1,
                __DIR__"master/jiumozhi" : 1,
        ]));
/*
> 鸠摩智说道：赵客缦胡缨，胡缨的样子应该是这样的，这是否暗指行掌之势？
鸠摩智开始认真考虑这个问题。

紧接着鸠摩智使出「祝融怀焰」，双手如抱圆球，内力运处，一股炙热无形刀气斩向血刀老
祖的右耳！
血刀老祖掉转身子，轻轻一跃，一式「狮子摇头」轻描淡写地化开鸠摩智这一招。

鸠摩智跃起一式「火内莲花」，左掌连劈，沸腾的劲力罩住血刀老祖的身子，右掌紧扬，一
刀斩向血刀老祖顶门！
结果只听见血刀老祖一声惨嚎，气浪已在血刀老祖左脸砍出一道深及见骨的可怕伤口！！
( 血刀老祖气喘嘘嘘，看起来状况并不太好。 )
*/
        set("no_fight", 1);
        set("no_beg", 1);
        set("no_clean_up", 0);
	set("coor/x", -3090);
	set("coor/y", -25090);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"