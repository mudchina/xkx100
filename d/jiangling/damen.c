//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "大门");
	set ("long", @LONG
这是荆州大名鼎鼎的武林人物万震山的住处。正值万老英雄五十大
寿，朱红大门外挂灯结彩，前来拜寿的客人谈笑着走进大厅，鼓乐手吹
着迎宾的乐曲。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"dating",
		"west"  : __DIR__"xijie4",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
