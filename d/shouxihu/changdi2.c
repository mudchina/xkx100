// Room: /yangzhou/changdi2.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "长堤春柳");
	set("long", @LONG
过虹桥，瘦西湖豁然开阔，西堤遍植杨柳，间以桃花。古有扬州宜
杨之说，传说是因隋炀帝开运河，河堤植柳，而炀帝赐垂柳姓杨，故杨
柳之称始于扬州。长堤柳丝拂水，柔情万种，所谓“多情最是扬州柳”。
堤中临水建有一亭，隐于柳荫中。柳丛中点缀红白桃花。桃红柳绿，倒
影水中，宛若天境。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"north" : __DIR__"taohuawu",
		"south" : __DIR__"chunliuting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 33);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}