//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "巫峡");
	set ("long", @LONG
巫峡跨越川、鄂两省，是三峡中最为幽深秀丽的一段峡谷，西段的
崖壁由层次很薄的白色岩层组成，褶皱非常厉害，看起来象古代武士头
顶的金盔，所以又叫金盔银甲峡。东段，北岸的崖壁裂缝中放有黑色的
悬棺，因此叫铁棺峡。如果说瞿塘峡象一道闸门，那么巫峡简直象江上
一条迂回曲折的走廊。船随山势左一弯，右一转，每一曲，每一折，都
向你展开一幅绝好的风景画。这里往西是瞿塘峡，东边是西陵峡。南边
有一座桥。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
                "west" : __DIR__"qutangxia",
                "east" : __DIR__"xilingxia",
                "south": __DIR__"dangyangqiao",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
