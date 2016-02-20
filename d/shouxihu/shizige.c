// Room: /yangzhou/shizige.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十字阁");
	set("long",@LONG
十字阁南经曲廊连平台东北隅，阁呈“十”字形，高二层，层结五
顶，上覆铬绿琉璃瓦和宝顶，中顶突出，似碧玉簪立。底层、楼层各面
皆围以槛窗，其建筑风格与熙春台和谐一致。底层面南两柱，悬挂楹联
(lian)。底层面北两柱，悬挂杜甫刘禹锡集句楹联(lian1)。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : "
胜地重彩在红藕花中绿杨荫里
箫声依旧看长天一色朗月当空
\n",
		"lian1" : "
        碧        浅
        瓦        黄
        朱        轻
        甍        绿
        照        映
        城        楼
        郭        台
\n",
	]));
	set("exits", ([
		"south" : __DIR__"pingtai5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50);
	set("coor/y", 110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}