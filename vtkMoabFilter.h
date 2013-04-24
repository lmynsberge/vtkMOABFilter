#ifndef __vtkMoabFilter_h
#define __vtkMoabFilter_h

#include "vtkPolyDataAlgorithm.h"

class VTKFILTERSGEOMETRY_EXPORT vtkMoabFilter : public vtkPolyDataAlgorithm
{
public: 
    static vtkMoabFilter *New();
	vtkTypeMacro(vtkMoabFilter, vtkPolyDataAlgorithm);
	void PrintSelf(ostream& os, vtkIndent indent);
	
protected:
    vtkMoabFilter();
	~vtkMoabFilter();
	
	virtual int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
};
	
#endif