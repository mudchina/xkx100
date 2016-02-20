// Room: /d/yueyang/yueyanglou1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "岳阳楼三楼");
	set("long", @LONG
洞庭山水抚慰了落魄的人生，人生的苦难也铸就了岳阳的灵魂。一
拨拨朝廷的弃儿，将一挂热泪抛洒在岳阳楼头时，巴陵的山捧着它，洞
庭的波含着它，分明就铸成了岳阳城头一块块苦涩的砖石，从屈夫子一
直垒砌到今天。站在此处，楚天远阔。楼匾高书“不以己悲”，谁能识
之？滕子京谪守岳州三年，《宋史》定评：“宗谅尚气，倜傥自任，好
施与，及卒，无余财。”真千秋风骨。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"down"  : __DIR__"yueyanglou2",
	]));
	set("coor/x", -1450);
	set("coor/y", -2260);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
