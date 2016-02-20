// Room: /d/fuzhou/gongxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "宫巷");
	set("long", @LONG
旧名仙居，以巷中有紫极宫得名，是当今福州保护得最完整的古巷
坊。巷内现存明代的建筑六幢，清代的建筑十三幢。其中面积在万平方
尺以上的深宅大院有十幢之多。福州历代尤以近代名人多居于巷内，如
清两江总督、福建船政大臣沈葆桢，林则徐之子林聪彝，清海军总长刘
冠雄等。宫巷里的豪门住宅结构精巧，单是室内的木雕石刻构件就今人
叹为观止。如漏花窗户采用缕空精雕，榫接而成，而且通过木格骨骼的
各种精心编排构成了丰富的图案装饰。在木穿斗、插斗、童柱、月梁等
部件上常饰以重点雕刻。各种精巧生动的石刻在柱础、台阶、门框、
花座、柱杆上随处可见。真可算是福州古建筑艺术集大成者。
LONG );
	set("exits", ([
		"west" : __DIR__"nanhoujie6",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6360);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
