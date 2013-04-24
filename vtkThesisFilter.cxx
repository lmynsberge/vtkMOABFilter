int vtkThesisFilter::RequestData(vtkInformation *vtkNotUsed(request), 
                                               vtkInformationVector **inputVector,
											   vtkInformationVector *outputVector)
{
     // Get the iinfro objects
	 vtkInformation *inInfo = inputVector[0]->GetInformationObject(0);
	 vtkInformation *outInfo = outputVector->GetInformationObject(0);
	 
	 // Get the input and output
	 vtkDataSet *input = vtkDataSet::SafeDownCast(inInfo->Get(vtkDataObject::DATA_OBJECT()));
	 vtkPolyData *output = vtkPolyData::SafeDownCast(outInfo->Get(vtkDataObject::DATA_OBJECT()));
	 
	 vtkIdType cellId, newCellId;
	 vtkIdType numCells=input->GetNumberOfCells();
	 vtkIdList *cellIds;
	 vtkCellData *CD = input->GetCellData();
	 vtkCellData *outputCD = output->GetCellData();
	 vtkGenericCell *cell;
	 
	 if (numCells == 0)
	     {
		 return 1;
		 }
		 
	cellIds = vtkIdList::New();
	cell = vtkGenericCell::New();
	
	int abort=0;
	for(cellId=0; cellId < numCells; cellId++)
	    {
		    