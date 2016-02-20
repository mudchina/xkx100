//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "当阳桥");
	set ("long", @LONG
一座古木桥，已经有点摇摇欲坠。当年张飞横矛立马桥头，厉声大
喝：“吾乃燕人张翼德也，谁敢与我决一死战？”其声如雷，桥梁震断，
河水倒流。桥头树着一块石碑 (bei)。过桥往北，是一条长长的峡谷，
江水在谷间咆哮，宛若千军万马奔腾东去。东面是城陵矶，西边是一个
小山坡。
LONG);
	set("outdoors", "jiangling");
	set("item_desc", ([
		"bei":"\n张翼德横矛处\n"                    
	]));

	set("exits", ([ 
		"south" : __DIR__"yidao1",
		"east"  : __DIR__"chenglingji",
		"north" : __DIR__"wuxia",
		"west"  : __DIR__"changbanpo",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
