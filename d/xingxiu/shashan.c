// room: /d/xingxiu/shashan.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "鸣沙山");
	set("long", @LONG
这是一座黄沙堆积形成的高数十丈的沙山。山峰陡峭，势如刀刃。
微风吹动，沙山发出嗡嗡的响声。故而当地人称之为鸣沙山。此山北麓
有月牙泉。登山俯瞰，沙丘林立，清泉荡漾。从山顶下滑沙砾随人体下
坠，鸣声不绝于耳，兴味盎然。故称“沙岭晴鸣”。
    沙土中似乎有一种虫子在蠕动。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northdown" : __DIR__"yueerquan",
		"eastdown"  : __DIR__"silk3",
		"west"      : __DIR__"wanxiangdong",
	]));
	set("objects", ([
		__DIR__"npc/shachong" : 1
	]));
	set("coor/x", -20320);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
