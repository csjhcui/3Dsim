/*****************************************************************************************************************************
This is a project on 3D_SSDsim, based on ssdsim under the framework of the completion of structures, the main function:
1.Support for 3D commands, for example:mutli plane\interleave\copyback\program suspend/Resume..etc
2.Multi - level parallel simulation
3.Clear hierarchical interface
4.4-layer structure

FileName�� buffer.h
Author: Zuo Lu 		Version: 1.9	Date:2017/10/11
Description:
buff layer: only contains data cache (minimum processing size for the sector, that is, unit = 512B), mapping table (page-level);

History:
<contributor>     <time>        <version>       <desc>													<e-mail>
Zuo Lu	        2017/04/06	      1.0		    Creat 3D_SSDsim											617376665@qq.com
Zuo Lu			2017/05/12		  1.1			Support advanced commands:mutli plane					617376665@qq.com
Zuo Lu			2017/06/12		  1.2			Support advanced commands:half page read				617376665@qq.com
Zuo Lu			2017/06/16		  1.3			Support advanced commands:one shot program				617376665@qq.com
Zuo Lu			2017/06/22		  1.4			Support advanced commands:one shot read					617376665@qq.com
Zuo Lu			2017/07/07		  1.5			Support advanced commands:erase suspend/resume			617376665@qq.com
Zuo Lu			2017/07/24		  1.6			Support static allocation strategy						617376665@qq.com
Zuo Lu			2017/07/27		  1.7			Support hybrid allocation strategy						617376665@qq.com
Zuo Lu			2017/08/17		  1.8			Support dynamic stripe allocation strategy				617376665@qq.com
Zuo Lu			2017/10/11		  1.9			Support dynamic OSPA allocation strategy				617376665@qq.com
*****************************************************************************************************************************/

struct ssd_info *buffer_management(struct ssd_info *);
struct ssd_info *no_buffer_distribute(struct ssd_info *);
struct ssd_info * getout2buffer(struct ssd_info *ssd, struct sub_request *sub, struct request *req);
struct ssd_info * check_w_buff(struct ssd_info *ssd, unsigned int lpn, int state, struct sub_request *sub, struct request *req);
struct ssd_info * insert2buffer(struct ssd_info *ssd, unsigned int lpn, int state, struct sub_request *sub, struct request *req);
struct sub_request * creat_sub_request(struct ssd_info * ssd, unsigned int lpn, int size, unsigned int state, struct request * req, unsigned int operation);
struct ssd_info * insert2_command_buffer(struct ssd_info * ssd, struct buffer_info * command_buffer, unsigned int lpn, int size_count, unsigned int state, struct request * req, unsigned int operation);
struct ssd_info * distribute2_command_buffer(struct ssd_info * ssd, unsigned int lpn, int size_count, unsigned int state, struct request * req, unsigned int operation);
struct allocation_info * allocation_method(struct ssd_info *ssd, unsigned int lpn, unsigned int use_flag);


unsigned int size(unsigned int);
__int64 calculate_distance(struct ssd_info * ssd, struct buffer_info * die_buffer, unsigned int lpn);
Status allocate_location(struct ssd_info * ssd, struct sub_request *sub_req);

struct ssd_info *handle_write_buffer(struct ssd_info *ssd, struct request *req);
struct ssd_info *handle_read_cache(struct ssd_info *ssd, struct request *req);