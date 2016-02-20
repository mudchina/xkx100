// /d/xiakedao/shiroom05.c 侠客岛 石室5

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
一位仙风道骨的老者正和一位高大的西域人切磋武功，两人均是
虚持空剑，招式忽快忽慢，阵阵劲风将室内得火把激荡得明暗不定，
石壁(wall)上图案亦是班驳陆离。
LONG );
        set("exits", ([
                "south" : __DIR__"shihole2",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「十步杀一人」几个大字。其下的图案却是一副工笔
山水，画的是山边密林，那树木的枝条长短不一，前后纵横，倒也笔
力雄健，栩栩如生。图旁有无数小注。
WALL
        ]));
        set("objects", ([
                __DIR__"master/ouyangfeng" : 1,
                __DIR__"master/ding"       : 1,
        ]));
/*
欧阳锋说道：十步一人，百步十人，人力有限，如何杀呢。
欧阳锋开始认真考虑这个问题。

欧阳锋突然挺身倒下，手中蛇杖一招「蛇游蟒走」，贴着地皮缠向丁春秋的左腿！
结果重重地击中，丁春秋「哇」地一声吐出一口鲜血！
( 丁春秋看起来可能受了点轻伤。 )

欧阳锋突然双手撑地，双足夹住蛇杖，裹着一阵风声打向丁春秋！
结果只听见「砰」地一声巨响，丁春秋像一捆稻草般飞了出去！！
( 丁春秋动作似乎开始有点不太灵光，但是仍然有条不紊。 )
*/
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
	set("coor/x", -3090);
	set("coor/y", -25190);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"