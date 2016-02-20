//Room: /d/dali/cangshan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","点苍山");
	set("long",@LONG
苍山之腹盛产奇石，世称大理石，又名点苍石、文石、础石。石
质细腻，色彩丰富，有彩花、水墨、银灰、雪白等品种。水墨最为稀
有，彩花独具特点，常用于作屏风观赏，有云树山川、人物鸟兽之形，
姿态万千，浑朴天成，为世所宝。银灰石是精美的建筑材料，用于贴
墙铺地，光润冰亮，气若云水，消暑生凉。雪花石又名点苍白玉，晶
莹可爱，白如截脂，是雕刻、绘画的好材料。石本以产于大理而得名，
而今天下凡此种花石皆称大理石，“大理”也因此石而名扬天下。
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "north"     : __DIR__"shilin",
	    "east"      : __DIR__"hongsheng",
	    "southwest" : __DIR__"xiaguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38000);
	set("coor/y", -56000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}