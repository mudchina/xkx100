// dadian.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIR "阎罗大殿" NOR);
 	set("long",HIW @LONG
这里是酆都大帝的宫殿，是阴曹地府的正殿，酆都大帝，也称阎罗
大帝，就是民间传说中的阎王；他高高地坐在大殿正中华丽的宝座上，
两边立着赏善司，罚恶司，阴律司和查察司四大判官，负责协助阎王审
查鬼魂们的生前善恶，以便决定是令其轮回转世，还是打入地狱永世受
苦。每个鬼魂来到这里，都是战战兢兢的。
LONG NOR 
	);
	set("no_fight", 1);
	set("exits", ([ 
		"south" : __DIR__"difu2",
		"east"  : __DIR__"tai",
	]));
	set("objects", ([
		__DIR__"npc/king": 1,
	        __DIR__"npc/shan": 1,
		__DIR__"npc/er"  : 1,
		__DIR__"npc/yinlu" :1,
		__DIR__"npc/chacha" :1,
	]) );

	setup();
	replace_program( ROOM );
}

