// Room: /d/wuxi/chaguan.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "二泉茶室");
	set("long", @LONG
一进来，正中是一幅丹青中堂，上绘一长袖飘飘之中年人，正乃茶
圣陆羽之像。以示这里所卖茶叶之正宗。满室飘着一股沁入心脾的茶香。
室内坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣
言，这里是个好所在。从侧面的窗户(window)可以俯视屋后的河水。
LONG );
	set("resource/water", 1);
	set("item_desc", ([
		"window" : 
"从窗户看去，清清的河水欢快地流淌，对面几个
女子正在河边浣洗衣服，不时传来阵阵嘻笑之声。\n",
	]));
	set("exits", ([
		"north" : __DIR__"westroad2",
	]));
	set("objects", ([
		__DIR__"npc/chaboshi" : 1,
	]));
	set("coor/x", 350);
	set("coor/y", -810);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}