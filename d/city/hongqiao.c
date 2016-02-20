// Room: /yangzhou/hongqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","虹桥");
	set("long",@LONG
虹桥是一座木制拱桥，围以红栏，因而初名「红桥」，后因横卧在
草河上，如同卧虹于波，才改「红」为「虹」。河的两岸遍植碧桃、杨
柳，每逢春暖花开之际，夭桃逞艳，柳浪闻莺，乃是扬州春日游人最销
魂的处所。古时四季均有修禊节，春禊正值阳历三月三，春暖花开，为
群相聚乐的游春赏景的节日。循晋王王羲之邀友引曲水以流觞，众宾吟
诗之风，此后这一节日深受文人雅士青睐，成为诗人聚会的盛大节日。
乾隆年间两淮盐运使卢雅雨效法前贤，作诗广为征和，文人雅士，布衣
平民依韵作和的有数千人。郑板桥，纪晓岚，袁枚都在其中。乾隆游此，
曾和乞丐对诗，传为美谈。登虹桥还可远眺秀丽湖色，招引游人，步入
胜境。 
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"north" : "/d/shouxihu/changdi1",
		"east"  : __DIR__"beimendajie",
		"west"  : __DIR__"caohebeijie",
	]));
	set("objects", ([
		"/d/wuxi/npc/lady2" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
